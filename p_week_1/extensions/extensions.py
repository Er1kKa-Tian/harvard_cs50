def main():

    usr_input = input("File Name: ").strip().lower()

    suffix = usr_input[(usr_input.rfind('.')+1):]

    match suffix:

        case "gif" | "png":
            path = f"image/{suffix}"

        case "jpg" | "jpeg":
            path = "image/jpeg"

        case "pdf" | "zip":
            path = f"application/{suffix}"

        case "txt":
            path = "text/plain"

        case _:
            path = "application/octet-stream"

    print(path)

if __name__ == "__main__":
    main()
