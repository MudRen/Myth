//Cracked by Roath
// zongguan.c ��������
// By yfeng,kittt


#include <ansi.h>
inherit NPC;
int ask_job();
int ask_join();
int leave_wg();
int give_up();
void init();
int do_tongbao();
void greeting(object ob);
int job_finish();

void create()
{

        set_name("��������", ({ "dongfang boyu", "dongfang", "boyu"}) );
        set("gender", "����" );
	set("per", 23);
        set("age", 42);
        set("long", "���������Ƕ�����ݵĹ��������Ϻ������¹���
���������Ī����������ͽ��Ϊ�١�\n");
        set("combat_exp", 80000);
	set("title", "��ݹ���");
	set("max_kee", 500);
	set("max_force", 200);
	set("force", 200);
	set("force_factor", 10);
	set_skill("parry", 70);
        set_skill("dodge", 70);
        set_skill("unarmed", 70);
	set_skill("force", 70);
//        carry_object("/d/obj/cloth/choupao")->wear();
	set("inquiry", ([
	        "name": "�Ϸ򶫷�����������ĵ��ҡ�\n",
                "here": "����ǰ�����������������ˣ���ѧ�յ��˺ܶ��ء�\n",
		"Ч��":		(: ask_job:),
		"job":		(: ask_job:),
                "�����":	(: ask_join:),
                "join":		(: ask_join :),
		"����":		(: give_up:),
		"give up":	(: give_up:),
		"fangqi":	(: give_up:),
		"������":	(: leave_wg:),
		"�˳�":		(: leave_wg:),
		"finish":       (: job_finish: ),
        ]));		
 
	setup();
        carry_object("/d/obj/cloth/choupao")->wear();
}

int job_finish()
{
       mapping job;
       object me=this_player();
       object ob=this_object();
       if(!(job=me->query_temp("wuguan/job")))
	{
		tell_object(me,CYN"��������˵��������û�����񣬺���ʲô��\n"NOR);
		return 1;
	}
       if (me->query_temp("wuguan/job_finish"))
        {
               return JOB_OB("wuguan")->real_give_gifts(me);
        }
       else 
        {
               tell_object(me,CYN"���������������õĿ����㣺�û������,���ɻ����?\n"NOR);
               return 1;
        }
       return 1;
}                          
int ask_job()
{
	object	 ob=this_player();
	
	return JOB_OB("wuguan")->ask_job(ob);
}

int give_up()
{
	object 	ob=this_player();
	if (ob->query_temp("wuguan/job"))
	{
		message_vision("��������ݺݵ�����$N�������⣺����û���˵��!\n",ob);
		return 1;
	}	
	
	return JOB_OB("wuguan")->give_up(ob);
}

int ask_join()
{
	object me;

	me = this_player();

	if((me->query("wuguan/join")))
	{
		message_vision(
CYN+"�����������$N˵������λ"+RANK_D->query_respect(me)+"���Ǳ���ݵ�һԱ�ˣ��ο࿪������Ц��\n"+NOR,me);
		return 1;
	}
	
	me->set("wuguan/join",1);
	me->set("newbie/learn", 1);
	me->save();
	message_vision(
CYN+"�����������$N��������������������ս������֣�"+RANK_D->query_respect(me)+"���ʲ���������������ɰɡ�\n"+NOR,me);
	message_vision(CYN"���������$N˵�����������������"NOR+HIY"(ask boyu about Ч��)"NOR+CYN"Ϊ�����Щ���ס�\n"NOR,me);
	return 1;
}

int leave_wg()
{
	object boyu,me;

	me=this_player();
	
	if(!me->query("wuguan/join"))
	{
		message_vision(
"���������$N˵�����㱾���Ͳ��Ǳ���ݵ��ˣ�����������ʲô�塣\n",me);
		return 1;
	}
	if (me->query_temp("wuguan/job"))
	{
		message_vision("���������$Nһ���ۣ�����Ҳ���Ȱ�����ͷ�Ļ����!\n",me);
		return 1;
	}	
	message_vision(
"��������̾�˿�����˵������Ȼ�����Ѿ����ҾͲ�ǿ�����ˡ������ն������Ϊ֮��\n",me);
//	command("chat �Ӽ�����"+me->name(1)+"�������Ҷ�����ݵĳ�Ա�ˡ�\n");
	me->delete("wuguan");
	me->delete_temp("wuguan");
	me->move(CITY_OB("wuguan","school1"));
	me->save();
	message_vision(
"$N�������ң��߳�����ݡ�\n",me);
	return 1;
}

void init()
{
	object me;
	
	me=this_player();
    if( (me->query("combat_exp")>10000 
        || me->query("maximum_force")>200 )&& !wizardp(me) )	{
		me->delete("guest");
		message_vision("����������һ�ӣ��������ڵ���Ϊ����Ӧ����������֣����߰ɡ�\n",me);
        me->move(CITY_OB("wuguan","school1"));
		return;
	}
	
	call_out("greeting",1,me);
	return;
}


void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
    if(ob->query("combat_exp")>10000)
		return;
	if(!ob->query("wuguan/join"))
	{
		message_vision(CYN"��������Ц������˵:"NOR+HIY"(ask boyu about �����)"NOR+CYN"���Լ����Ҷ�����ݡ�\n"NOR,ob);
		return;
	}
	if(!ob->query_temp("wuguan/job"))
	{
		message_vision(CYN"��������˵����"NOR+HIY"(ask boyu about Ч��)"NOR+CYN"�Ϳ���Ϊ���������Щ��������ЩǮ�ˡ�\n"NOR,ob);
		return;
	}
	message_vision(CYN"����������ɫһ�������������ҿ���˭͵�����ɱ���Ҳ����顣 ��\n"NOR,ob);
	return;
}

	

	
		
