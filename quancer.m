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

kp = 2; kd = 0.2; pf = 200;
qc_set_model_arguments(modelName,args_2)
qc_update_model(modelName);
qc_build_model(modelName)
num_bytes = qc_download_model(modelName)
res = qc_load_model(target_uri_1,modelName)


sys1dl= ['quarc_run -D -t '  target_uri_1  modelName '.rt-linux_rt_armv7' std_args];
sys2dl= ['quarc_run -D -t '  target_uri_2  modelName '.rt-linux_rt_armv7' std_args];
system(sys1dl);
system(sys2dl);


kp1 = 2; kd1 = 0.2;
gain_arg1 = [' -Kp ' num2str(kp1,4) ' -Kd ' num2str(kd1,4)];
sys1run = ['quarc_run -l -t '  target_uri_1  modelName '.rt-linux_rt_armv7' gain_arg1 std_args];

kp2 = 4; kd2 = 0.1;
gain_arg2 = [' -Kp ' num2str(kp2,4) ' -Kd ' num2str(kd2,4)];
sys2run = ['quarc_run -l -t '  target_uri_2  modelName '.rt-linux_rt_armv7' gain_arg2 std_args];

tic;
system(sys1run);
toc;
system(sys2run);




%!quarc_run -r -t tcpip://172.22.11.10:17000?keep_alive=1 servoPDF.rt-linux_rt_armv7 -Kp 0.2 -Kd 0.2 -d /tmp -uri tcpip://linux-dev:17001 
%!quarc_run -r -t tcpip://172.22.11.2:17000?keep_alive=1 servoPDF.rt-linux_rt_armv7 -Kp 2 -Kd 0.2 -d /tmp -uri tcpip://linux-dev:17001 

pause(12)
!quarc_run -u -t tcpip://172.22.11.10:17000?keep_alive=1 servoPDF.rt-linux_rt_armv7 -d /tmp -uri tcpip://linux-dev:17001 
copyfile servoPDF.mat servoPDF-1.mat
!quarc_run -u -t tcpip://172.22.11.2:17000?keep_alive=1 servoPDF.rt-linux_rt_armv7 -d /tmp -uri tcpip://linux-dev:17001 
copyfile servoPDF.mat servoPDF-2.mat

load servoPDF-1.mat
figure; plot(rt_t,rt_theta)
load servoPDF-2.mat
hold on; plot(rt_t,rt_theta,'r')
grid on;
xlabel('t (s)'); ylabel('theta (rad)')
legend({'Agent-1','Agent-2'})

abreak

