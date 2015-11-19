# -*- mode: ruby -*-
# vi: set ft=ruby :

VAGRANTFILE_API_VERSION = "2"

Vagrant.configure(VAGRANTFILE_API_VERSION) do |config|

  config.vm.box = "lucid32"
  config.vm.box_url = "http://files.vagrantup.com/lucid32.box"

  $script = %Q{
    sudo apt-get update
    sudo apt-get install build-essential nasm genisoimage bochs bochs-x bochs-sdl -y
  }
  
  config.vm.provision :shell, :inline => $script
  config.ssh.forward_x11 = true
  
end
