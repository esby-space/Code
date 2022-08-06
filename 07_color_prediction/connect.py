import time
from pySerialTransfer import pySerialTransfer as txfer


def main():
    link = txfer.SerialTransfer("/dev/cu.usbmodem101")

    try:
        link.open()
        time.sleep(2)

        while True:
            # get arduino values
            handle_error(link)
            if link.available():
                rgb = (int(link.rxBuff[0]), int(link.rxBuff[2]), int(link.rxBuff[4]))
                print(rgb)

            else:
                handle_error(link)

    except:
        link.close()


def handle_error(link: txfer.SerialTransfer):
    if link.status < 0:
        if link.status == txfer.CRC_ERROR:
            print("ERROR: CRC_ERROR")
        elif link.status == txfer.PAYLOAD_ERROR:
            print("ERROR: PAYLOAD_ERROR")
        elif link.status == txfer.STOP_BYTE_ERROR:
            print("ERROR: STOP_BYTE_ERROR")
        else:
            print("ERROR: {}".format(link.status))


if __name__ == "__main__":
    main()
