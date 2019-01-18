//Cracked by Roath

inherit NPC;

void create()
{
       set_name("����", ({"lao zhe","old man"}));
       set("long","һ����ͷ�׷������ߡ�\n");
       set("gender", "����");
       set("age", 66);
       set("combat_exp", 1800);
       set("daoxing", 1800);
        setup();
        carry_object("/obj/loginload/linen")->wear();

}

void init()
{
	object me=this_player();
	object ob=this_object();
	object here;
	add_action("do_agree","agree");
	here= find_object("/d/qujing/huangfeng/indoor");
        here = load_object("/d/qujing/huangfeng/indoor");
	
	if( me->query("obstacle/yz") !="done" 
	|| !(me->query_condition("eyeill")) 
	|| environment(ob)!=here)
	return;
	message_vision("$N����$n�����ӣ�æ˵���������ۼ�������������\n",ob,me);		
	message_vision("$N���Ժ����ĵ��ͷ����������$n�ж���\n",me,ob);
	call_out("move_sleeproom",2,me,ob);
}
int move_sleeproom(object me,object ob)
{	object here, where;
	here=environment(me);
	message_vision("$N����$n��������ȥ��\n",me,ob);
	me->move("/d/qujing/huangfeng/sleeproom");
	me->set_temp("enterroom","yes");
	ob->move("/d/qujing/huangfeng/sleeproom");
	where=environment(me);
	message_vision("$N����$n���˽�����\n",me,ob);
	call_out("say_sth",2,me,ob);
	return 1;
}
int say_sth(object me,object ob)
{
	message_vision("$Nָ�Ų�ϯ��$n˵��������������Ϣ(sleep)һ�£���ȥȡ�㶫����\n",ob,me);
	message_vision("˵�꣬$Nһת�����ˡ�\n",ob);
	destruct(ob);
	return 1;
}

int do_agree(object me,object ob)
{
	me=this_player();	
	ob=this_object();
	if(me->query_temp("lingjiask")!="yes")
	return 0;
	message_vision("$N��ͷ��������Ը��Щ�������ԡ�\n",me);
	call_out("start_doit",1,me,ob);
	return 1;
}
int start_doit(object me,object ob)
{
	message_vision("$N�漴ȡ��һ�����ʯ��С�޶������ο����ڣ���������պ������"+
		"��$n���ϡ�\n",ob,me);
        me->apply_condition("eyeill", 0);
        me->receive_curing("kee", 50);
        me->receive_heal("kee", 50);
	me->set_temp("need_sleep","yes");
	call_out("done_it",1,me,ob);
	return 1;
}
int done_it(object me,object ob)
{
	object where;
	message_vision("$N��$n˵������˯һ��������ͺá�\n˵�꣬ת�����ˡ�\n",ob,me);
	
	where= find_object("/d/qujing/huangfeng/indoor");
        where= load_object("/d/qujing/huangfeng/indoor");
	ob->move(where);
	me->start_busy(2);
	call_out("me_sleep_",1,me);

	return 1;
}

int me_sleep_(object me)
{	
	message_vision("$N�����۾���������Ϣ�ˡ�\n",me);	
	call_out("me_sleep",1,me);
	return 1;
}
int me_sleep(object me)
{	object dan;
	dan=new("/d/qujing/huangfeng/obj/dingfeng");
	me->set("last_sleep",time()-270);
        me->interrupt_me();
        me->command_function("sleep"); 
	me->move("/d/qujing/huangfeng/shanlu1");
	me->set_temp("lingji1_done","yes");
	dan->move(me);
	return 1;
}




	





