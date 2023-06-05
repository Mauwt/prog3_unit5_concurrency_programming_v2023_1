#!/usr/bin/env bash

project_name=prog3_unit5_concurrency_programming_v2023_1

# Create Template
mkdir ../${project_name}_template -p
rsync -au .github ../${project_name}_template/
rsync -au autograder ../${project_name}_template/
rsync -au src ../${project_name}_template/
cp template/src/*.cpp ../${project_name}_template/src
cp template/src/*.h ../${project_name}_template/src
mkdir ../${project_name}_template/tools -p
rsync -au tools/catch ../${project_name}_template/tools/
#rsync -au tools/docker ../${project_name}_template/tools/
rsync -a -f"- */" -f"+ *" ./ ../${project_name}_template
rm -f ../${project_name}_template/autograder_generator.sh
rm -f ../${project_name}_template/template_generator.sh

echo 'template folder has been synchronized correctly'