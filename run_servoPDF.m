modelName = 'servoPDF'
open_system(modelName)
target_uri_1='tcpip://172.22.11.2:17000?keep_alive=1 ';
target_uri_2='tcpip://172.22.11.10:17000?keep_alive=1 ';

std_args = ' -d /tmp -uri tcpip://linux-dev:17001';


args = '';
args_1 = ['-t ' target_uri_1]
args_2 = ['-t ' target_uri_2]

qc_set_model_arguments(modelName,args_1)
result = qc_load_model(target_uri_1, modelName, args)
num_bytes = qc_download_model(modelName)
%qc_start_model(modelName)

kp = 2; kd = 0.2; pf = 200; t_run = 3.99;
qc_set_model_arguments(modelName,args_2)
qc_update_model(modelName);
qc_build_model(modelName)
num_bytes = qc_download_model(modelName)
res = qc_load_model(target_uri_1,modelName)



sys1dl= ['quarc_run -D -t '  target_uri_1  modelName '.rt-linux_rt_armv7' std_args];
sys2dl= ['quarc_run -D -t '  target_uri_2  modelName '.rt-linux_rt_armv7' std_args];
system(sys1dl);
system(sys2dl);


kp1 = 90; kd1 = 0.05; 
td1 = 0.045;   % code execution start delay - specified from the tic/toc
gain_arg1 = [' -Kp ' num2str(kp1,4) ' -Kd ' num2str(kd1,4)];
sys1run = ['quarc_run -l -t '  target_uri_1  modelName '.rt-linux_rt_armv7' gain_arg1 ' -td ' num2str(td1) std_args];
sys1get = ['quarc_run -u -t '  target_uri_1  modelName '.rt-linux_rt_armv7' std_args];

kp2 = 0.4; kd2 = 0.1; 
td2 = 0;
gain_arg2 = [' -Kp ' num2str(kp2,4) ' -Kd ' num2str(kd2,4)];
sys2run = ['quarc_run -l -t '  target_uri_2  modelName '.rt-linux_rt_armv7' gain_arg2 ' -td ' num2str(td2) std_args];
sys2get = ['quarc_run -u -t '  target_uri_2  modelName '.rt-linux_rt_armv7' std_args];

tic;
system(sys1run);
toc;
system(sys2run);

%!quarc_run -r -t tcpip://172.22.11.10:17000?keep_alive=1 servoPDF.rt-linux_rt_armv7 -Kp 0.2 -Kd 0.2 -d /tmp -uri tcpip://linux-dev:17001 
%!quarc_run -r -t tcpip://172.22.11.2:17000?keep_alive=1 servoPDF.rt-linux_rt_armv7 -Kp 2 -Kd 0.2 -d /tmp -uri tcpip://linux-dev:17001 
%!quarc_run -u -t tcpip://172.22.11.10:17000?keep_alive=1 servoPDF.rt-linux_rt_armv7 -d /tmp -uri tcpip://linux-dev:17001 
%!quarc_run -u -t tcpip://172.22.11.2:17000?keep_alive=1 servoPDF.rt-linux_rt_armv7 -d /tmp -uri tcpip://linux-dev:17001 

pause(t_run+2+1)
system(sys1get);
copyfile servoPDF.mat servoPDF-1.mat
save servoPDF-1  kp1 kd1 -append 

system(sys2get);
copyfile servoPDF.mat servoPDF-2.mat
save servoPDF-2  kp2 kd2 -append 

load servoPDF-1.mat
rt_theta_1 = rt_theta;
figure; plot(rt_t,rt_theta)
load servoPDF-2.mat
rt_theta_2 = rt_theta;
hold on; plot(rt_t,rt_theta,'r')
grid on;
xlabel('t (s)'); ylabel('theta (rad)')
hold on; plot(rt_t,rt_theta_1-rt_theta_2,'k--')
grid on;
legend({'Agent-1','Agent-2'})

%abreak

