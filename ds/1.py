import os

def create_readme(directory):
    readme_content = "# Directory Contents\n\n"
    
    # Traverse through all files in the directory
    for filename in os.listdir(directory):
        filepath = os.path.join(directory, filename)
        
        # Skip directories and only consider files
        if os.path.isfile(filepath):
            description = "No description available."  # Placeholder for description
            
            # Open the file and read its first line as a description (optional)
            with open(filepath, 'r', encoding='utf-8', errors='ignore') as file:
                first_line = file.readline().strip()
                if first_line:
                    description = first_line
            
            # Add the filename and description to the README content
            readme_content += f"## {filename}\n\n{description}\n\n"

    # Write the README content to a file, overwriting any existing content
    with open(os.path.join(directory, 'README.md'), 'w') as readme_file:
        readme_file.write(readme_content)
    
    print("README.md file created successfully and content has been overwritten.")

# Provide the directory path here
directory_path = r"C:\Users\KIIT\Desktop\data structure apna college\ds"
create_readme(directory_path)
