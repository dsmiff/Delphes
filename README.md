GETTING STARTED WITH CMS VERSION OF DELPHES
===========================================

Set up GitHub per instructions on http://cms-sw.github.io/cmssw/usercode-faq.html (and linked pages)
Then do:
 
git clone https://github.com/sethzenz/Delphes.git
cd Delphes
./configure
make


Quick start with Delphes
========================

Commands to get the code:

   wget http://cp3.irmp.ucl.ac.be/downloads/Delphes-3.0.10.tar.gz

   tar -zxf Delphes-3.0.10.tar.gz

Commands to compile the code:

   cd Delphes-3.0.10

   make

Finally, we can run Delphes:

   ./DelphesHepMC

Command line parameters:

   ./DelphesHepMC config_file output_file [input_file(s)]
     config_file - configuration file in Tcl format
     output_file - output file in ROOT format,
     input_file(s) - input file(s) in HepMC format,
     with no input_file, or when input_file is -, read standard input.

Let's simulate some Z->ee events:

   wget http://cp3.irmp.ucl.ac.be/downloads/z_ee.hep.gz
   gunzip z_ee.hep.gz
   ./DelphesSTDHEP examples/delphes_card_CMS.tcl delphes_output.root z_ee.hep

or

   curl -s http://cp3.irmp.ucl.ac.be/downloads/z_ee.hep.gz | gunzip | ./DelphesSTDHEP examples/delphes_card_CMS.tcl delphes_output.root

For more detailed documentation, please visit 

https://cp3.irmp.ucl.ac.be/projects/delphes/wiki/WorkBook
