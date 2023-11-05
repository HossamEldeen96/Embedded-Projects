 


#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_


void i2c_Inite(void);

void i2c_send(u8 data);
typedef enum {
	I2C_ok,
	I2C_SC_Error,
	I2C_RSC_Error,
	I2C_MT_SLA_W_Error,
	I2C_MR_SLA_R_Error,
	I2C_MT_Data_Error,
	I2C_MR_Data_Error,

}I2C_Error;

/*Macros for Checking(Master Transmit)*/
#define I2C_SC_ACK            0x08
#define I2C_RSC_ACK           0x10
#define I2C_MT_SLA_W_ACK      0x18
#define I2C_MT_DATA_ACK       0x28


/*Macros for Checking(Master Receive)*/
#define I2C_MR_SLA_R_ACK        0x40
#define I2C_MR_DATA_ACK  0x80

void I2C_MASTER_INIT(void);
void I2C_SLAVE_INIT(u8 slave_address);

I2C_Error I2C_Send_Start_Condition(void);
I2C_Error I2C_Send_Repeated_Start_Condition(void);
I2C_Error I2C_Send_Slave_Address_Write(u8 slave_add);
I2C_Error I2C_Send_Slave_Address_Read(u8 slave_add);
I2C_Error I2C_Send_Master_Send_Byte(u8 master_data);
I2C_Error I2C_Send_Master_Read_Byte(u8 *master_data_read);
void      I2C_Send_Stop_Condition(void);

u8 I2C_slave_avialable(void);


#endif /* I2C_INTERFACE_H_ */