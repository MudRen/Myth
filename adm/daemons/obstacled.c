//Cracked by Roath
// obstacled.c
// by blacksh 01/06/99

// ȡ�����鸺���ڲ���ȡ����,ȡ����ȫ�ֱ���

#pragma optimize

#include <ansi.h>

inherit F_DBASE;
inherit F_SAVE;



void create()
{
    object env,qujingren;
    object me=this_object();

    seteuid(getuid());
    set("name", "ȡ������");
    set("id", "obstacled");
    if (!restore())		//��һ�λ������³�ʼ����
      {

      }
    else
      {
        if (me->query("haved_qujingren")==1)
 	  {
            env=load_object(me->query("where_qujingren"));
                       //ȡ�������һ�γ��ֵĵط�
            if (env && env->query("short")!="������")
              {
  	        qujingren=find_living("qujing ren");
                if (!qujingren)
	          {
		    qujingren=new("/d/qujing/qujingren/"+me->query("guan")
                                +"/qujingren");
	          }
    	        qujingren->move(env);
  	      }
	  }	
     }

  if (me->query("haved_qujingren")==1)
    {
      return ;	//�Ѿ�����ȡ���� 
    }  

  remove_call_out("choose_qjr");
  call_out("choose_qjr",3600*24*5);   //�������һ��ȡ����
	

}


void choose_qjr()
{	//��ʼѡ��ȡ����

  	object   env,tang,me;

	me=this_object();
	env=load_object("/d/huanggong/dadian");
	tang=present("xu",env);
	tang->command_function("chat �������,�ʵ�گԻ����Ѱ����ǰ������ȡ��
��ɮ֮��ʿ����������ʿǰ����ѡ��ѡ�б������ͣ��մ�");	
	me->set("choose_qjr",1);
	me->add("this_qj_time");
	me->set("number",0);
	me->set("min_time",0);
	remove_call_out("over_choose_qjr");
        call_out("over_choose_qjr",3600*24);    //��һ������Ҳ�ѡ
						
}


void over_choose_qjr()
{	//ѡȡ���˽���
	
  	object  env,tang,me;
	int 	number,choose_number;
	mixed 	qujing_times;
	string 	*keys,min,id,name;
	int 	size,i,inc=0;
	mixed   inchoose,temp;


	me=this_object();
	env=load_object("/d/huanggong/dadian");
	tang=present("tang",env);
        me->delete("choose_qjr");
	number=me->query("number");

	if (number<1)
	  {
	    tang->command_function("chat  �������ô��ƣ���Ȼ��һӢ�ۣ�");
  	    remove_call_out("choose_qjr");
	    call_out("choose_qjr",3600*24*5);	//�������һ��ȡ����
	    return;
	  }

	if (number==1)
	  {
	    id=me->query_temp("chooseman/1/id");
	    name=me->query_temp("chooseman/1/name");
	    tang->command_function("chat* ��"+name+"("+id+")Ϊ������ʦ,"
		+"����ȡ����ǰ������ȡ����");
	    me->set("husong",id);	
            me->delete("obstacl_fail");
	    return;
	  }


	
	qujing_times=me->query("qujing_times");	//�ڵ����������趨��صĲ���
	keys=keys(qujing_times);
	size=sizeof(qujing_times);
        inchoose = allocate (size);
	
		
	min=keys[0];
	for (i=1;i<size;i++)
	  {
	    if ( min<keys[i] )	//ѡ������ʧ�ܴ��������ϵ��
	      {
		temp=me->query("qujing_times/"+keys[i]);
 	      }
	    else
	      {
		temp=me->query("qujing_times/"+min);
		min=keys[i];
	      }
  	    inchoose[inc]=temp[random(sizeof(temp))];	
		//�����ϵ����ѡ��һ����ң��ŵ�inchoose
	    inc++;
	  }

	i=inchoose[random(inc)];	
	me->set("qujing_times/"+min+"/"+i,i);
		//ѡ��һ����Ҽ��뵽����ѡ��
	size=sizeof(me->query("qujing_times/"+min));
	i=me->query("qujing_times/"+min+"/"+random(size));
	
	//���ε�������:
	//�������ȡ��ʧ�ܵĴ��������ѡȡȡ���ˣ�
	//�����ų�������ȡ����������ң�
	//Ȼ�����ո��ԵĴ������ѡ�������е���ң�
	//��ѡ���Ľ���ŵ�inchoose�У�����������ѡ��һ�����
	//���������ҷŵ��ŵ����ٴ�����ϵ�У�
	//�������ϵ����ѡ��һ����ң������Ҿ������ѡ����ȡ���ˣ�

	//��ε������Ҫ��Ϊ�˸�����ʧ�ܵ��˸���Ļ��ᣮ


/*	
	if (number>1)
	  {
	    choose_number=random(number+1);
	    if (choose_number==0)
	      {
		choose_number=me->query("min_man"); //��ʱ����̵��˶������
	      }

	  }
*/

         id=me->query_temp("chooseman/"+i+"/id");
	 name=me->query_temp("chooseman/"+i+"/name");
	 tang->command_function("chat* ��"+name+"("+id+")Ϊ������ʦ,"
		+"����ȡ����ǰ������ȡ����");
	 me->set("husong",id);	
	 return;


}



int remove()
{
	save();
	return 1;
}

string query_save_file() { return DATA_DIR + "qujing/obstacled"; }


void back_fabao()
{	//��������Ҫ��һ��Сʱ�ڷ��ط���
 
  remove_call_out("backme");
  call_out("backme",3600);

}

void back()
{
   object fabao,env;

   fabao=find_object("tianmo jian");				
   if (fabao)
     {
	env=environment(fabao);
	if (interactive(env))env=environment(env);  
	message("sound","����һ�����,���õļһ�,������ħ����\n",env);
   	destruct(fabao);
     }
   this_object()->delete("last_jie_id")	;

}

void punish_player(object who)
{	//���ȡ���˱��,ȡ��ʧ��,�������������ͷ�
	//�������ȡ���˱��Ժ�,������Ҳ�һ������,�����Ҫ��
	//logind���޸��������������߾���punish_player();

     who->delete("obstacle/qujing");

}


void qujing_fail()
{
  remove_call_out("do_qujing_fail");
  call_out("do_qujing_fail",3600);
}

void do_qujing_fail()
{	//ȡ���˱�ץ24Сʱ���û�б��ȳ�������ȡ��ʧ��.(��������:D)
  
   object me,who;
   me=this_object();
   who=this_player();


   me->set("obstacle_fail",1);
   me->save();

   if (who=find_player(OBSTACLE_D->query("husong")))
      {
	punish_player(who);
      }
   
}

 


void open_door()
{
  remove_call_out("do_open_door");
  call_out("do_open_door",120);
}

void do_open_door()
{
  this_object()->set("open_door",1);
}
