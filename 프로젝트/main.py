import serial
import time
import tkinter as tk

# 🔴 COM 포트만 수정
SERIAL_PORT = "COM9"
BAUD_RATE = 9600

ser = serial.Serial(SERIAL_PORT, BAUD_RATE)
time.sleep(2)  # 아두이노 리셋 대기

def toggle_servo():
    ser.write(b't')

# ===== GUI =====
root = tk.Tk()
root.title("Servo Controller")
root.geometry("250x120")

btn = tk.Button(
    root,
    text="Servo Toggle (0° ↔ 180°)",
    font=("Arial", 12),
    command=toggle_servo
)
btn.pack(expand=True)

def on_close():
    ser.close()
    root.destroy()

root.protocol("WM_DELETE_WINDOW", on_close)
root.mainloop()
