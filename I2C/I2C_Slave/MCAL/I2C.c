#include "StdTypes.h"
#include "MemMap.h"
#include "Utels.h"
#include "I2C_Interface.h"


void i2c_Inite(void)
{
	//enable i2c
	SET_BIT(TWCR,TWEN);
	
	
}

void i2c_send(u8 data)
{
	//Send START condition
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	//Wait for TWINT Flag set. This indicates that the START condition has been	transmitted
	while (!READ_BIT(TWCR ,TWINT));
	
	
}




void I2C_MASTER_INIT(void)
{
	/*  Set prescaller 0  */
	CLR_BIT(TWSR,TWPS0);
	CLR_BIT(TWSR,TWPS1);
	
	/*  Set CLK 100kHZ -> Fcpu= 8MHZ  */
	//TWBR=32;
	
	/*  Set CLK 100kHZ -> Fcpu= 16MHZ */
	TWBR=72;

	/*            Enable ACK          */
	SET_BIT(TWCR,TWEA);

	/*            Enable I2C           */
	SET_BIT(TWCR,TWEN);
}

void I2C_SLAVE_INIT(u8 slave_address)
{
	 /*    Set Slave Address   */
	 TWAR = slave_address<<1;
	 
	 /*            Enable ACK          */
	 SET_BIT(TWCR,TWEA);

	 /*            Enable I2C           */
	 SET_BIT(TWCR,TWEN);
	 
	 
}

I2C_Error I2C_Send_Start_Condition(void)
{
	I2C_Error Local_var = I2C_ok;

	/*  I2C Start Conversion  */
	SET_BIT(TWCR,TWSTA);
	
	/*      Clear Flag        */
	SET_BIT(TWCR,TWINT);
	
	/*      Polling on the Flag        */
	while(READ_BIT(TWCR,TWINT)==0);
	
	/*  Check on ACK*/
	if((TWSR & 0xF8)!=0x08)
	{
		Local_var = I2C_SC_Error;
	}
	return Local_var;
}
I2C_Error I2C_Send_Repeated_Start_Condition(void)
{
	I2C_Error Local_var = I2C_ok;

	/*  I2C Start Conversion  */
	SET_BIT(TWCR,TWSTA);
	
	/*      Clear Flag        */
	SET_BIT(TWCR,TWINT);
	
	/*      Polling on the Flag        */
	while(READ_BIT(TWCR,TWINT)==0);
	
	/*  Check on ACK*/
	if((TWSR & 0xF8)!=I2C_RSC_ACK)
	{
		
		Local_var = I2C_RSC_Error;
	}
	return Local_var;
}
I2C_Error I2C_Send_Slave_Address_Write(u8 slave_add)
{
	I2C_Error Local_var = I2C_ok;
	
	// for write you should put 0 on LSB
	// load slave address into data register
	TWAR = slave_add<<1; // write operation
	CLR_BIT(TWAR,0);	 // write
	// start transmission of address
	TWCR = (1<<TWINT) | (1<<TWEN);
	// wait for end of transmission
	while( SET_BIT(TWCR,TWINT) == 0);
	
	if((TWSR & 0xF8)!=0X18)
	{
		
		Local_var = I2C_MT_SLA_W_Error;
	}
	return Local_var;
}
I2C_Error I2C_Send_Slave_Address_Read(u8 slave_add)
{
	I2C_Error Local_var = I2C_ok;
	
	// for write you should put 0 on LSB
	// load slave address into data register
	TWDR = slave_add<<1; // write operation
	SET_BIT(TWDR,0);	 // read
	// start transmission of address
	TWCR = (1<<TWINT) | (1<<TWEN);
	// wait for end of transmission
	while( READ_BIT(TWCR,TWINT) == 0);
	
	if((TWSR & 0xF8)!=I2C_MR_SLA_R_ACK)
	{
		
		Local_var = I2C_MR_SLA_R_Error;
	}
	return Local_var;
}
I2C_Error I2C_Send_Master_Send_Byte(u8 master_data)
{
	I2C_Error Local_var = I2C_ok;
	
	TWDR = master_data;
	TWCR = (1<<TWINT) | (1<<TWEN);
	
	/*      Polling on the Flag        */
	while(READ_BIT(TWCR,TWINT)==0) {  }
	
	if((TWSR & 0xF8)!=I2C_MT_DATA_ACK)
	{
		
		Local_var = I2C_MT_Data_Error;
	}
	return Local_var;
	
}
I2C_Error I2C_Send_Master_Read_Byte(u8 *master_data_read)
{
	I2C_Error Local_var = I2C_ok;
	
	// start TWI module and acknowledge data after reception
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA);
	// wait for end of transmission
	while( READ_BIT(TWCR,TWINT) == 0);
	// return received data from TWDR
	
	
	if((TWSR & 0xF8)!=I2C_MR_DATA_ACK)
	{
		
		Local_var = I2C_MR_Data_Error;
	}
	else
	{
		*master_data_read = TWDR;
	}
	return Local_var;
	
}
void      I2C_Send_Stop_Condition(void)
{
	
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
}

u8 I2C_slave_avialable(void)
{
	TWCR  = (1<<TWEN) | (1<<TWINT) |(1<<TWEA);
	while( READ_BIT(TWCR,TWINT) == 0);
	if(TWSR == 0x60) return 1;
	else return 0;
}