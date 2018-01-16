**GIT**

**BASIC:**
Modifications are made in the working directory -> Modified files are added to the **stage** -> Added to the repository after a **commit**

**HEAD** -> location of where you are right now. (git show HEAD)
**Remote** -> A shared repository that allows many collaborators

**PREREQUISITES:**

sudo apt-get install git -> Installs git
A GitHub account

COMMANDS:

git --version
git config --global user.name "user_name"
git config --global user.email "email_id"

**git init** -> Initialise a folder as a Git repository
**git status** -> See current status of the repo
**git add f_name** -> Adds the f_name to the stage
**git reset HEAD filename** -> removes the file from the staging area to the commit at HEAD. or can use only f_name
**git log**-> list of prevoious commits
**git commit -m "message here"** -> From stage to repo.
**git diff f_name** -> Checks the difference between last commit and present changes(if any) | git diff --staged f_name -> to see difference of staged file


**git checkout commit-id/HEAD filename** -> Reverts all changes of the filename back to where the commit was. You can use HEAD.
**git checkout b_name** -> goes to branch b_name
**git branch / b_name** -> Which branch I am on? / creates a new branch b_name
**git branch -d b_name** -> Deletes the branch b_name
**git checkout -- target_file_name** -> reverts file to last commit


**git clone remote_location clone_name** -> remote_location- place on the web(filename, web address)
										    clone_name- The name of the repo to clone into (local copy)
**git remote add remote_name remote_location** -> Adds a remote as remote_name from remote_location
**git remote -v** -> Shows the remotes

**git fetch** -> Checks if any changes in the remote and brings those changes on a remote branch(origin/master)
**git push origin b_name** -> Pushes branch to the remote | if you use -u, command line will remember the parameters so next time you can use 							"git push"
**git pull** -> pulls changes from the remote repository

**git tag tag_name** -> creates a tag tag_name
