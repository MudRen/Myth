//NPC  /d/city/npc/kaoguan.c
//Created by waiwai@2000/08/20

#include <command.h>
inherit NPC;
#include <ts.h>
#include <localtime.h>
int give_quest(object ob);
int now_time();

void create()
{
	set_name("������",({"fan juren","fan","juren","fanjuren"}));
	set("age",56);
	set("str",23);
	set("ts_ok",1);
	set("degree",WHT"����"NOR);

	set("inquiry",([
		"here":"������ͯ���������뿼�ԵĻ�����ÿ���ǽ�ϵĸ�ʾ(gaoshi).\n",
		"����":"��ǽ�ϵĸ�ʾ�ɡ�\n",
	]));
	setup();
}

void init()
{
	::init();
	add_action("do_exam","exam");
	add_action("do_answer","answer");
}

int do_exam()
{
	object ob;
	int level;
	string rank;

	ob=this_player();
	if (!ob||environment(ob)!=environment()) return 0;

	if (ob->query_skill("literate",1)<10) 
		return notify_fail("������ҡͷ�����������д�ֽ���Щ������.\n");

	if ((int)ob->query("ts_ok")>1) 
		return notify_fail("������������һ�۵������Ѿ������ˣ���\n");

	if ((int)ob->query("office_number")>1) 
		return notify_fail("������������һ�۵������Ѿ������ˣ���\n");

	level=ob->query("office_number");

	if (level)  {
	       rank=ob->query("degree");
       	if (level>query("ts_ok"))
		       return notify_fail(HIG"�����پ��ȵ���"+rank+HIG"���ˣ���Ҫ����Ц�ˣ���\n"NOR);
	       return notify_fail(HIY"�����پ��ȵ���������"+rank+HIY"������ʲôͯ����?\n"NOR);
        }

	if (now_time()==ob->query("ts/last_check")) 
		return notify_fail("������������һ�۵������������ɣ���\n");

	if (ob->query_temp("ts/answer"))
		return notify_fail("������ָ����������⻹û�ش��!\n");

	message_vision("$N��$n������ʩ�����������˳���!\n",ob,this_object());

	give_quest(ob);
	return 1;
}

int give_quest(object ob)
{ 
	mapping quest;
	string *text,word,pass;
	int i;
	quest=exam[random(sizeof(exam))];
	text=quest["text"];
	i=random(sizeof(text));

	if (random(2)==1) {
		if (i!=0) {  word=text[i-1]; pass="ǰһ��";}
		      else {word=quest["author"];pass="����";}
      } else { 
	if (i!=(sizeof(text)-1)) { word=text[i+1]; pass="��һ��"; }
        else { word=quest["title"]; pass="��Ŀ"; }
      }
	ob->set_temp("ts/answer",word);
	command("say ["+text[i]+"... ...],����"+pass+"�ǣ�\n");
	return 1;
}

int do_answer(string arg)
{
	object ob=this_player();

	if ((int)ob->query("office_number")>1) 
		return notify_fail("������˵����һ����ȥ��\n");

	if(!ob->query_temp("ts/answer") && !wizardp(ob) ) 
		return notify_fail("������Ц�����ҿɻ�û���⣬���˵Щʲô?\n");

	message_vision("$N��˼���ã���������𰸿���["+arg+"]?\n",ob);

	if( arg ==ob->query_temp("ts/answer") ) {
		command("nod");
	message("shout",
	HIY"\n��"HIR"ͯ������"HIY"��"HIR"�����ˣ���ϲ"+log_id(ob)+"˳����ȡͯ����\n"NOR,users());

		ob->set("ts_ok",2);
		ob->set("degree","ͯ��");
		ob->add("office_number",1);
		ob->delete_temp("ts");
		ob->delete("ts/last_check");
	log_file("ts.rc",
	HIR+log_id(ob)+NOR WHT" ��["+BJTIME_CMD->chinese_time(1, ctime(time()))+NOR WHT"] "HIY"��ȡͯ����\n"NOR);
	return 1;
	}

	command("shake");
	command("say ��Ҫ���ģ�����������\n");
	ob->delete_temp("ts");
	if( !wizardp(ob) )
	ob->set("ts/last_check",now_time());
	return 1;
}

int now_time()
{
	int i;
	object ob=this_player();
	mixed *local;
	local = localtime(time()*60);
	i=local[LT_MDAY] + (local[LT_HOUR]>23? 1 : 0);
	return i;
}
  
