//Cracked by Roath
// job.c �������

#include <ansi.h>
int ask_job(object ob);
int give_up(object ob);
int give_gifts(object ob);
int real_give_gifts(object ob);

mapping *jobs = ({
	([	"job_type":		"wuguan",
		"job":			"����",
		"bonus":		50,
		"exp":			70,
		"pot":			30,
		"money":		5,
		"msg":			
HIC"�����������˵������������������Ҫһ���㣬�㵽����ȥ
��һ����"HIY"(diao ��)"HIC"�͵����������\n"NOR
	]),
	([	"job_type":		"wuguan",
		"job":			"����",
		"bonus":		50,
		"exp":			50,
		"pot":			30,
		"money":		5,
		"msg":			
HIC"�����������˵���������Ļ𹤽��첡�ˣ���ȥ����Щ��"HIY"
(pi ��)"HIC"��Ȼ�����Ÿɲ񵽳���ȥ����"HIY"(sheng ��)"HIC"��\n"NOR
	]),
	([	"job_type":		"wuguan",
		"job":			"ɨ��Ժ",
		"bonus":		50,
		"exp":			50,
		"pot":			30,
		"money":		5,
		"msg":			
HIC"�����������˵������Ժ����ѻ��˲��ٵ���Ҷ����ȥ����
��ɨ"HIY"(sao ��Ժ)"HIC"һ�¡�\n"NOR
	]),
/*
	([	"job_type":		"wuguan",
		"job":			"����",
		"bonus":		50,
		"exp":			50,
		"pot":			30,
		"money":		5,
		"msg":			
HIC"�����������˵�������������ã��������ֲ�������ȥ��С
��Ҫ����"HIY"(ask xiao hong about tea)"HIC"���õ�����ȥ���ŵ�����
��"HIY"(fang ��)"HIC"��\n"NOR
	]),
*/
	([	"job_type":		"wuguan",
		"job":			"�������",
		"bonus":		50,
		"exp":			50,
		"pot":			30,
		"meony":		5,
		"msg":			
HIC"�����������˵������ȥ����һ�����"HIY"(zhengli ���)"HIC"����
���Ѿ��þ�û����ʰ�ˣ������ҵĲ�����,�����ˣ�������
�����ٲ��ɾ�"HIY"(ca ���)"HIC"��\n"NOR
	]),
	([	"job_type":		"wuguan",
		"job":			"����",
		"bonus":		50,
		"exp":			50,
		"pot":			30,
		"money":		5,
		"msg":			
HIC"�����������˵������Ժ�˵��Ӳݴ������������ģ�ȥ����
������Ӳݳ�һ�°�"HIY"(chu  ��)"HIC"��\n"NOR
	]),
	([	"job_type":		"wuguan",
		"job":			"��ˮ",
		"bonus":		50,
		"exp":			50,
		"pot":			30,
		"money":		5,
		"msg":			
HIC"�����������˵������Ժ�˵س��Ʋ�̫�ã�������ȱˮ�����ӣ�
�ȵ�ˮ����Ͱˮ"HIY"(da ˮ)"HIC"��Ȼ��ȥ��Ժ�˵ؽ�ˮ"HIY"(jiao ˮ)"HIC"��\n"NOR
	]),
	});

// Ҫ����
int ask_job(object ob)
{
	mapping		job;

	if(!ob->query("wuguan/join"))  //������ݳ�Ա
	{
		message_vision(
CYN "���������ܳ�������"+RANK_D->query_respect(ob)+"���Ǳ���ݵ��ˣ���Ч�͡����������ˡ�\n" NOR,ob);
		return 1;
	}
	
	// ����ݳ�Ա
	if(ob->query_temp("wuguan/job"))  //������job
	{
		tell_room(ob,CYN "��������������ü���㻹���Ȱ���ͷ�ϵĻ������˵�ɡ�\n" NOR);
				return 1;
	}
	else  //not job
	{
	// ������job
		job=jobs[random(sizeof(jobs))];
		ob->set_temp("wuguan/job",job);
		tell_object(ob,job["msg"]);
		return 1;
	}
}

// ��������
int give_up(object ob)
{
	mapping job;

	if(!(job=ob->query_temp("wuguan/job")))
	{
		tell_object(ob,CYN"��������˵��������û�����񣬺���ʲô��\n"NOR);
		return 1;
	}
	
	ob->delete_temp("wuguan");
	tell_object(ob,CYN"��������˵������Ȼ��θɲ���Ҳû��ϵ���´���Ŭ���ɡ�\n"NOR);
	ob->add("combat_exp",-((int)job["bonus"]/10+random(job["exp"]/10)));
	if(ob->query("combat_exp")<0)
		ob->set("combat_exp",0);
	return 1;	
}

// ������
int give_tool(object ob,object npc)
{
	mapping job;
	object objTool;
	
   seteuid(getuid());
	if(!(job=ob->query_temp("wuguan/job")))
	{
		message_vision(
"����¶���$N˵������ʲô����û�У���������ƭ����ô��\n",ob);
		return 1;
	}
	if(ob->query_temp("wuguan/tool"))
	{
		tell_object(ob,
"�����˵�������Ȱ��ϻؽ�Ĺ��߻�����˵��\n");
		return 1;
	}
		
	switch(job["job"])
	{
		case	"����":
			objTool=new(__DIR__"obj/yugan");
			break;
		case	"����":
			objTool=new(__DIR__"obj/chaidao");
			break;
		case	"ɨ��Ժ":
			objTool=new(__DIR__"obj/saozhou");
			break;
		case	"�������":
			objTool=new(__DIR__"obj/mabu");
			break;
		case	"����":
			objTool=new(__DIR__"obj/chutou");
			break;
		case	"��ˮ":
			objTool=new(__DIR__"obj/piao");
			break;
		default:
			message_vision(CYN
"�����˵���������ڵĹ���������Ҫʲô���ߡ�\n"NOR,ob);
		return 1;
		break;
	}
	
	objTool->move(ob);
	ob->set_temp("wuguan/tool",objTool->query("id"));
	message_vision("�����˵��������"+objTool->query("name")+"���úã����������˻�������\n",ob);
	tell_object(ob,"��õ�һ"+objTool->query("unit")+objTool->query("name")+"��\n");
	return 1;
}

// ���չ���
int accept_tool(object npc,object ob,object obj)
{
	if(!ob->query_temp("wuguan/tool"))
	{
		message_vision(
"$n��$NЦ������ô����¸�ң��ҿɲ��ᱻ�㸯ʴ�ġ�\n",ob,npc);
		return 0;
	}
	if(interactive(obj))
		return notify_fail("�����ʲô�������˿ڣ�\n");
	if(obj->query("id")!=ob->query_temp("wuguan/tool"))
		return notify_fail("�ⶫ������ս��ô��\n");
	
	message_vision(
"$n����$N��ͷ������Ц���������ġ�\n",ob,npc);
	ob->delete_temp("wuguan/tool");
	call_out("destruct_tool",1,obj);
	return 1;
}

void destruct_tool(object obj)
{
	destruct(obj);
	return;
}

// ����
int give_gifts(object ob)
{
        ob->set_temp("wuguan/job_finish",1);
        return 1;
}        
int real_give_gifts(object ob)
{
	int exp,pot,silv;
	mapping job=ob->query_temp("wuguan/job");
	
	ob->add("combat_exp",(exp=(int)job["bonus"]+random(job["exp"])));
	ob->add("potential",(pot=(int)job["bonus"]/2+random(job["pot"])));
	MONEY_D->pay_player(ob,(silv=(int)job["bonus"]/10+random(job["money"]))*100);
	tell_object(ob,CYN"����������������ļ��:�ɵĺ�,���Ǹ������Ǯ!\n"NOR);
	tell_object(ob,
HIY"��ϲ����"+chinese_number(exp)+"��ʵս���飬"+chinese_number(pot)+"��Ǳ��!\n"NOR);
        tell_object(ob,"�����������һЩ����.\n");
	ob->delete_temp("wuguan/job");
	ob->set_temp("wuguan/job_finish",0);
	return 1;
}
	
	
// ɨ��Ժ
int job_saodayuan(object ob,string arg)
{
	int exp,pot,silv;
	mapping job;

	if(!arg||(arg!="��Ժ"))
	{
		return notify_fail("����ɨʲô��\n");
	}	
	if(!(job=ob->query_temp("wuguan/job")))
		return notify_fail("��Ժ����ͦ�ɾ��ģ�������ɨ�ˡ�\n");
	if(job["job"]!="ɨ��Ժ")
		return notify_fail("�����ڵĹ�������ɨ��Ժ���Ȱ���ͷ�Ļ������˵�ɡ�\n");
	if(!present("sao zhou",ob))
		return notify_fail("����ʲôɨ�أ����·�ô��\n");
	if(ob->is_busy())
		return notify_fail("��ɨ�ÿ죬��һ��ɨ�øɾ����������ɡ�\n");
	if(ob->query("kee")<10)
		return notify_fail("��ľ��������޷����У�Ъ����ɨ�ɡ�\n");
	
	ob->start_busy(1);
	if(ob->query_temp("wuguan/saodayuan")<20)
	{
		ob->add_temp("wuguan/saodayuan",1);
		ob->receive_damage("kee",5);
		return notify_fail("������ɨ�㣬һ��һ�µ�ɨ������\n");
	}
	if(random(100) > 80)
	{
		message_vision(
"$N������ƽʱ��̫�Ͷ�����Ȼ��Ժ��ԽɨԽ���ˡ�\n",ob);
		ob->receive_damage("kee",5);
		return 1;
	}
			
	message_vision(
"$N������ɨ�㣬�ɵ��Ȼ��죬��һ�ᣬ��Ժ��ɨ�ĸɸɾ�����\n",ob);
	ob->receive_damage("kee",10);
	ob->delete_temp("wuguan/saodayuan");
	return give_gifts(ob);
}

// ����
int job_diaoyu(object ob,string arg)
{
	mapping		job;

	if(!(job=ob->query_temp("wuguan/job")))  //û��job
	{
		tell_object(ob,CYN "С������㣺�ˣ���û�о����ܹܵ�ͬ�⣬�����������Ҫ��Ǯ�ġ�\n" NOR);
		message_vision(CYN "$N���°�ĭ����󵹷��˳�ȥ��\n" NOR ,ob);
		return 1;
	}
	if((job["job"])!="����") //job ���ǵ���
	{
		tell_object(ob,"�㻹���Ȱ���ͷ�Ļ������˵�ɡ�\n");
		return 1;
	}
	//����job
	if(!arg)
		return notify_fail("�����ʲô��\n");
	if(arg!= "��")
		return notify_fail("��Ҫ���Ķ���������û�С�\n");
	if(ob->is_busy())
		return notify_fail("����Ҫ�����ģ�������������ææ����ô�������㡣\n");
	if(ob->query_temp("wuguan/fishing"))
		return notify_fail("�㲻����������ô���𼱣�\n");
	if(!present("yu gan",ob))
		return notify_fail("��û�������ô���㣿\n");
	if(ob->query("sen") < 20)
		return notify_fail("�㾫��̫�ã���ô���㣿\n");
	if(ob->query_temp("wuguan/fish"))
		return notify_fail("��̫̰�ˣ���һ����͹��ˡ�\n");
	
	message_vision("$N�ó�һ����ͣ�����������������\n",ob);
	ob->start_busy(1);
	ob->set_temp("wuguan/fishing",1);
	call_out("end_fishing",30,ob);
	return 1;
}

int end_fishing(object ob)
{
	object obj;
	
	ob->delete_temp("wuguan/fishing");
	if(random(100) < 30)
	{
		ob->receive_damage("sen",10);
		tell_object(ob,"����˰��쾢��ȴû����һ���㡣\n");
		message_vision("$N�Ե�������ɥ��\n",ob);
		return 1;
	}
	
	obj=new(__DIR__"obj/fish");
	obj->move(ob);
	ob->receive_damage("sen",15);
	ob->set_temp("wuguan/fish",1);
	tell_object(ob,"��������������³�����һ����ͣ���Ȼ�㹳�Ϲ���һ���㡣\n");
	message_vision(CYN"$N���˵�����������\n"NOR,ob);
	return 1;
}

int give_fish(object npc,object ob,object obj)
{
	mapping job;
		
	if(!(job=ob->query_temp("wuguan/job")))
		return notify_fail(CYN"�����������ɻ�����������ո�ʲô��\n"NOR);
	if(job["job"]!="����")
		return notify_fail(CYN"������˵���������ڲ���Ҫ�ⶫ�������Լ������ðɡ�\n"NOR);
	if(obj->query("id")!="li yu")
		return notify_fail(CYN"������˵��:����ʲô����ѽ?\n"NOR);
	
	ob->delete_temp("wuguan/fish");
	call_out("destruct_fish",1,obj);
	message_vision(
CYN"$nЦ�����ض�$N˵������˾����ܸɣ����ն������ɡ�\n"NOR,ob,npc);
	return give_gifts(ob);
}

void destruct_fish(object obj)
{
	if(objectp(obj))
		destruct(obj);
	return;
}

// ��ˮ
int job_dashui(object ob,string arg)
{
	mapping 	job;
	
	if(!arg||(arg!="ˮ"))
		return notify_fail("�����ʲô��\n");
	if(!(job=ob->query_temp("wuguan/job")))
		return notify_fail("�����ڲ����������ˮ��\n");
	if(job["job"]!="��ˮ")
		return notify_fail("����æ�����ȥ�ɡ�\n");
	if(!present("tong",ob))
		return notify_fail("��Ͱ��û�ˣ�����ʲô��ˮ��\n");
	
	message_vision("$N�ߵ����ߣ�������ҡ��������ڴ�����һͰˮ��\n",ob);
	ob->receive_damage("kee",10);
	ob->start_busy(3);
	return 1;
}

// ��ˮ
int job_jiaoshui(object ob,string arg)
{
	int exp,pot,silv;
	mapping job;

	if(!arg||arg!="ˮ")
		return notify_fail("���뽽ʲô��\n");
	if(!(job=ob->query_temp("wuguan/job")))
		return notify_fail("����Ĳ�ˮ�ֳ��㣬��Ϲ��ʲô��\n");
	if(job["job"]!="��ˮ")
		return notify_fail("�����ڵĹ������ǽ�ˮ���Ȱ���ͷ�Ļ������˵�ɡ�\n");
	if(!present("tong",ob))
		return notify_fail("��û����ˮͰ����ô��ˮ��\n");
	if(!present("piao",ob))
		return notify_fail("��û��ư����ʲô��ˮ��\n");
	if(ob->is_busy())
		return notify_fail("����������̫���� \n");
	if(ob->query("kee")<10)
		return notify_fail("�����ھ������ã����ۻ��ˡ�\n");
		
	ob->start_busy(1);
	if(ob->query_temp("wuguan/jiaoshui")>20)
	{
		if(random(100)>20)
		{
			ob->delete_temp("wuguan/jiaoshui");
			message_vision("$N��Ͱ���ˮ���꣬����԰����Ĳ˳��ø���ʢ�ˡ�\n",ob);
			return give_gifts(ob);
		}
		
		return notify_fail("������ư��㽽�˼��£��������������ġ�\n");
	}
	
	ob->add_temp("wuguan/jiaoshui",1);
	ob->receive_damage("kee",3);
	return notify_fail("��Ҩ��һưˮ���������ϡ�\n");
}

// ����
int job_chucao(object ob,string arg)
{

	int exp,pot,silv;
	mapping job;

	if(!arg||(arg!="��"))
		return notify_fail("�����ʲô��\n");
	if(!(job=ob->query_temp("wuguan/job")))
		return notify_fail("��û�Ӳݣ���������ˡ�\n");
	if(job["job"]!="����")
		return notify_fail("�����ڵĹ������ǳ��ݣ��Ȱ���ͷ�Ļ������˵�ɡ�\n");
	if(!present("chu tou",ob))
		return notify_fail("��û��ͷ����ʲô�ݣ�\n");
	if(ob->is_busy())
		return notify_fail("�����ô�죬������Ǳ�Ǯ��\n");
	if(ob->query("kee")<10)
		return notify_fail("����ˣ�����ˣ������ٸ��ˡ�\n");
	
	ob->start_busy(1);
	if(ob->query_temp("wuguan/chucao")>20)
	{
		if(random(100) > 20)
		{
			ob->delete_temp("wuguan/chucao");
			message_vision(CYN"���������Ŭ����$N���ڽ��˵�����Ӳݳ��ɾ��ˡ�\n"NOR,ob);
			return give_gifts(ob);
		}
		
		return notify_fail("��һ�����񣬰ѺúõĲ��������˳�����\n");
	}
	
	ob->add_temp("wuguan/chucao",1);
	ob->receive_damage("kee",3);
	return notify_fail("�������ͷ��һ��һ�µس���������\n");
}

// ����
int job_pichai(object ob,string arg)
{
	object obj;
	
	if(!arg||(arg!="��"))
		return notify_fail("������ʲô��\n");
	if(!present("chai dao",ob))
		return notify_fail("����ʲô��������˺ô��\n");
	if(ob->query("kee") < 10)
		return notify_fail("�����ھ���������ǿ�����񣬿��ܻ�������Σ�ա�\n");
	if(ob->is_busy())
		return notify_fail("�������ڵĵ���������̫����ܻ�Ҫ���Լ���С����\n");
	
	message_vision("$N����һ��ľͷ��\n",ob);
	if(random(100) < 20)
	{
		message_vision("$Nһ��������ȥ�����������ַ�̫���������Լ��Ľš�\n",ob);
		ob->receive_damage("kee",10);
		ob->receive_damage("sen",10);
		return 1;
	}
	
	ob->add_temp("wuguan/pichai",1);
	message_vision(
			"$N��ľ��������߾ٲ񵶣����һ����������ľ�顰�ǡ���һ���������ˡ�\n",ob);
	obj=new(__DIR__"obj/chai");
	obj->move(environment(ob));
	ob->start_busy(1);
	ob->receive_damage("kee",5);
	return 1;
}

// ����
int job_shenghuo(object ob,string arg)
{
	object objChai;
	mapping job;
	
	if(!arg||(arg!="��"))
		return notify_fail("�����ʲô��\n");
	if(!(job=ob->query_temp("wuguan/job")))
		return notify_fail("���������ʲô����Ż�ô��������\n");
	if(job["job"]!="����")
		return notify_fail("������û���������㵽������ʲô�𣡣�\n");
	if(ob->is_busy())
		return notify_fail("һ���ӰѲ����ȥ����ѻ�ѹ��ġ�\n");
	if(!(objChai=present("chai",ob)))
		return notify_fail("�㶼û�в񣬻������𣬷����ǲ��ǡ�\n");
	if(ob->query("kee")<10)
		return notify_fail("�����ھ������ܼ��У�С�İ���������ˡ�\n");
	if(ob->query_temp("wuguan/fire"))
		return notify_fail("���ⲻ�������Ż���ô��\n");
	if(!ob->query_temp("wuguan/pichai"))	
		return notify_fail("�����û��ȥ���������Ĳ��\n");
	
	ob->add_temp("wuguan/pichai",-1);	
	destruct(objChai);
	ob->start_busy(3);
	ob->set_temp("wuguan/fire",1);
	call_out("over_sheng",3,ob);
	message_vision(
"$N�ó�һ�������һ�����ţ��ŵ�¯���\n",ob);
    return 1;
}

int over_sheng(object ob)
{
	ob->delete_temp("wuguan/fire");
	if(random(100)<65)
	{
	 	ob->receive_damage("kee",5);
	 	message_vision(
"$N���˰��쾢��������Ѭ�������è����ȴû�ѻ����š�\n",ob);
        return 1;
	}
	
	message_vision(
"����"+HIR"����"NOR+"Խ��Խ����$N���𴵻���ӽ����˼��£����ڰѻ������ˡ�\n",ob);
	ob->receive_damage("kee",10);
	return give_gifts(ob);
}

// �������
int job_zhengli(object ob,string arg)
{
	mapping 	job;
	
	if(!arg||(arg!="���"))
		return notify_fail("��Ҫ����ʲô��\n");
	if(!(job=ob->query_temp("wuguan/job")))
		return notify_fail("������ڲ���Ҫ������\n");
	if(job["job"]!="�������")
		return notify_fail("�����ڵĹ�������������ܣ��Ȱ���ͷ�Ļ������˵�ɡ�\n");
	if(ob->query_temp("wuguan/cashujia"))
		return notify_fail("���Ѿ�������ˡ�\n");
	if(ob->query("kee")<10)
		return notify_fail("������ľ������ܼ��У��������Խ��Խ�ҡ�\n");
	if(ob->is_busy())
		return notify_fail("����ϸ�Ҫ��������\n");
	
	ob->add_temp("wuguan/zhenglishujia",1);
	if(ob->query_temp("wuguan/zhenglishujia")<15)
	{
		ob->add_temp("zhenglishujia",1);
		ob->start_busy(1);
		ob->receive_damage("kee",5);
		return notify_fail("�㽫��һ��һ�����ű���ķźá�\n");
	}
	
	ob->receive_damage("kee",8);
	ob->delete_temp("wuguan/zhenglishujia");
	ob->set_temp("wuguan/cashujia",1);
	tell_object(ob,"�㽫���ϵĻҳ��ĵ�����������Ӧ�ð���ܲ��ɾ��ˡ�\n");
	return 1;
}

// �����
int job_cashujia(object ob,string arg)
{
	mapping job;

	if(!arg||(arg!="���"))
		return notify_fail("�����ʲô��\n");
	if(!(job=ob->query_temp("wuguan/job")))
		return notify_fail("�������ͦ�ɾ��ģ���������ˡ�\n");
	if(job["job"]!="�������")
		return notify_fail("�����ڵĹ������ǲ���ܣ��Ȱ���ͷ�Ļ������˵�ɡ�\n");
	if(!present("ma bu",ob))
		return notify_fail("����������˸ж�����������·�Ҳ���ɾ��������ҿ�Ĩ�������ɣ�\n");
	if(!ob->query_temp("wuguan/cashujia"))
		return notify_fail("�������黹�Ÿ����߰��㣬�����ʲô����\n");
	if(ob->query("kee")<10)
		return notify_fail("���޷����о�������ܲ��ɾ���\n");
	if(ob->is_busy())
		return notify_fail("����ô���ʲô��һ�㶼�����ġ�\n");
	
	if(ob->query_temp("wuguan/cashujia")<10)
	{
		ob->start_busy(1);
		ob->add_temp("wuguan/cashujia",1);
		ob->receive_damage("kee",5);
		return notify_fail("������Ĩ����һ��һ�µĲ�����ܡ�\n");
	}
	
	message_vision(
"$N���˰��쾢�����ڽ���ܲ��øɸɾ�����$N�����õ�����������İڷ�������\n",ob);
	ob->receive_damage("kee",8);
	ob->delete_temp("wuguan/cashujia");
	return give_gifts(ob);
}

// Ҫ��
int job_asktea(object ob)
{
	mapping job;
	object objTea;
	
	if(!(job=ob->query_temp("wuguan/job")))
	{
		message_vision(CYN"С��˵����û���ܹܷԸ����ҿɲ��Ҹ����ϺõĲ衣\n"NOR,ob);
		return 1;
	}
	if(job["job"]!="����")
	{
		message_vision(CYN"С��������������������ۣ��Һ�����ʹ����û���ܹܷԸ����ҿɲ��Ҹ����ϺõĲ衣\n"NOR,ob);
		return 1;
	}
	if(ob->query("kee")<10)
	{
		message_vision(CYN"С���$N˵������̫�����ˣ�������˲裬Ҳ�����ģ�������Ϣһ�°ɡ�\n"NOR,ob);
		return 1;
	}
	if(present("wulong tea",environment(ob)))
	{
		message_vision(CYN"С��˵������Ϲ����û����������ô��\n"NOR,ob);
		return 1;
	}
	if(present("wulong tea",ob))
	{
		message_vision(CYN"С��������ü��˵�������������̰�ģ��㲻���Ѿ�����ô��\n"NOR,ob);
		return 1;
	}
	
	message_vision(
CYN"$N���������һҾ��������˵��������������˿��ˣ��ܹܴ��˼��㷱æ����������������Ͳ衣\n"NOR,ob);
	message_vision(
CYN"С������һЦ���Ǿ������������������Ǹ���õĶ�������������ȥ�ɡ�\n"NOR,ob);
	ob->receive_damage("kee",5);
	ob->set_temp("wuguan/tea",1);
	ob->delete_temp("wuguan/wrong");
	objTea=new(__DIR__"obj/wulongtea");
	objTea->move(ob);
	tell_object(ob,"����һ��"+YEL"������"NOR+"��\n");
	return 1;	
}

int wrong_way(object ob,string room,string dir)
{
	mapping path=([
				"huayuan":		"east",
				"xiaojing5":	"north",
				"shibanlu6":	"east",
				"dayuan":		"southup",
				]);

	object objTea;
	
	if(ob->query_temp("wuguan/wrong") && dir==path[room])
		return 0;
	if(ob->query_temp("wuguan/tea"))
	{
		if(!ob->query_temp("wuguan/path/"+room))
		{
			if(random(100)<50)
			{
				message_vision(HIR"$Nһ��ûվ�ȣ�����һ�ӣ������������ˤ���˵��ϡ�\n"NOR,ob);
				if(objTea=present("wulong tea",ob))
					destruct(objTea);
				ob->receive_damage("kee",5);
				ob->delete_temp("wuguan/tea");
				ob->set_temp("wuguan/wrong",1);//�޶���·����
				ob->set_temp("wuguan/path/"+room,1);
				if(dir==path[room])
					return 0;
			}
		}
	}
	
	return 1;
}

// �Ų�
int job_fangcha(object ob,string arg)
{
	mapping 	job;
	object objTea;
		
	if(!arg||(arg!="��"))
		return notify_fail("�����ʲô?\n");
	if(!(job=ob->query_temp("wuguan/job")))
		return notify_fail("�㲻�ܰѶ����ŵ����\n");
	if(job["job"]!="����")
		return notify_fail("����æ�����ȥ�ɣ����ﲻ��Ҫ�㡣\n");
	if(!(objTea=present("wulong tea",ob)))
		return notify_fail("��û�������裬��������ʲô��\n");
	
	ob->delete_temp("wuguan/tea");
	ob->delete_temp("wuguan/path");
	if(!objTea->query("value") )
	{
		message_vision(
"���������ܹ���,��ž��������$Nһ�������Ķ��⣬��������ⲻ�����Ķ���������͵�ȣ����ɣ�\n",ob);
		ob->delete("wuguan");
		ob->receive_damage("sen",50);
		ob->set("kee",1);
		ob->move(CITY_OB("wuguan","schoolhall"));
		destruct(objTea);
		message_vision(
"ֻ��$N���������ı������˳�����ˤ�˸��������ס�\n",ob);
		return 1;
	}
	
	message_vision("$N���������Ľ�һ���Ϻõ�"+YEL"������"NOR+"�ŵ����ϡ�\n",ob);
	destruct(objTea);
	ob->receive_damage("kee",10);
	return give_gifts(ob);
}
