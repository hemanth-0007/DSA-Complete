from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC

driver = webdriver.Chrome()
driver.get('https://web.whatsapp.com/')
driver.maximize_window()

input('Authenticate WhatsApp with QR code.')

contact = input('Enter the name of contact: ')

# Wait for the contact to load
contact_xpath = f'//span[contains(@title, "{contact}")]'
contact_element = WebDriverWait(driver, 20).until(EC.presence_of_element_located((By.XPATH, contact_xpath)))
contact_element.click()

n = int(input('Enter no of msgs.: '))
text = input('Enter text: ')

input_field_xpath = '//*[@id="main"]/footer/div[1]/div/span[2]/div/div[2]/div[1]/div/div[1]'
input_field_element = WebDriverWait(driver, 15).until(EC.presence_of_element_located((By.XPATH, input_field_xpath)))
for i in range(n):
    try:
        # Find the input field and send the message
        input_field_element.send_keys(text, '\n')
        # Wait for the message to be sent
        # WebDriverWait(driver, 10).until(EC.invisibility_of_element_located((By.XPATH, input_field_xpath)))
    except Exception as e:
        print("An error occurred while sending the message:", e)
        break

print(n, 'messages sent successfully to', contact)
