# Diffie-Hellman Key Exchange Project

This project demonstrates the Diffie-Hellman key exchange algorithm implemented using SystemC. It is designed to be built and run within a Docker container to ensure a consistent environment.

## Prerequisites

- Make sure to have Docker installed and running on your local machine.

## Building the Docker Image

1. Ensure you have the `Dockerfile`, `Makefile` and **source codes** in the same directory.

2. Build the Docker image with the following command:

    ```bash
    docker build -t my_systemc_project .

    ```

## Running the Docker Container

To start a Docker container and get an interactive shell, use the following command:

```bash
docker run -it my_systemc_project /bin/bash

```

This command will open a shell inside the Docker container.

## Running the Project

Once inside the Docker container, follow these steps:

1. Navigate to the working directory:

```bash
    cd /usr/src/myapp

```

2. Build the project (if not already built during Docker image creation):

```bash
make

```

3. Run the executable:

```bash
./out

```


## Updating the Project

1. Make changes to the source code or `Makefile` as needed.

2. Rebuild the Docker image to include these changes:

```bash
docker build -t my_systemc_project .

```

3. Rerun the container and execute the updated application as described above.


## Notes

- Ensure that the Dockerfile correctly installs SystemC and sets up environment variables.

- The `out` file should be executable. If it is not, add execute permissions using:

```bash
chmod +x ./out

```


## Troubleshooting

- Check Docker build logs for errors if you encounter issues.

- Verify SystemC installation by checking the installation paths and environment variables inside the container.

For further questions or issues, please refer to the documentation or seek help from the project maintainers.
