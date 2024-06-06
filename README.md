# who_unfollowed
Simple program that tells you which Instagram profiles don't follow you back WITHOUT using Instagram's API and runs locally so you don't get banned.

To use this program, you will need to request to [download your data](https://help.instagram.com/181231772500920/?helpref=uf_share) from Meta (instagram)!

-----

## Usage
First, clone this repository:  
```
git clone https://github.com/rwintgen/who_unfollowed.git
```  

Then, go in the folder and compile the program:  
```
cd who_unfollowed
make
```  

Finally, launch the program:  
```
./who_unfollowed [pathname] -[option] [arguments]
```  

-----

## Arguments and options
### Arguments
`pathname`: The location of the directory containing the information about followers and following. 

### Options
`--outfile / -o [filename]`: writes output to outfile whose path corresponds to `filename`. Will default to create a file in current working directory if none specified.  
`--list / -l`: prints all followers and following as human-readable data.  
`--sort / -s`: prints all followers and following sorted aplhabetically and by category (mutually followed accounts, followed by you, following you).  
`--export / -x [format]`: output will be in the format specified by `format`. Currently compatible with `.xls` only.  
`--help / -h`: prints the help panel.

## Uninstall

Remove all content by running the command:
```
make uninstall
```  


**Happy figuring out who didn't want to hear from you anymore! :)**
