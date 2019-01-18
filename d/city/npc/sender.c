//qinping.c

//created 5-10-97 pickle

/************************************************************/

#include <ansi.h>
inherit F_MASTER;
inherit NPC;
string try_me();
int total=random(20);
mapping count=([]);
/************************************************************/

void create()
{
  set_name("���μǿ��", ({"semder", "sender", "master"}));
        set("long", "�����ϴ��и��ֱ����ͽ��(armor)�������Ҫ���������(yao)��\n");
  set("gender", "����");
  set("age", 46);
  set("str", 30);
  set("int", 25);
  set("max_sen", 200);
  set("max_kee", 600);
  set("force", 500);
  set("max_force", 400);
  set("force_factor", 20);
  set("combat_exp", 80000);
  setup();
  set("inquiry", ([
		   "����": (: try_me :),
		   "�¼�": (: try_me :)
]) );
  

}



void init()
{
  add_action("do_yao", "yao");
  add_action("do_huan", "huan");
}

int do_yao(string arg)
{
  object me=this_player(), npc=this_object(), obj;
  
  if( !arg ||
     (arg != "blade"
   && arg != "sword"
   && arg != "fork"   
   && arg != "spear"
   && arg != "hammer"
   && arg != "staff"
   && arg != "stick"
   && arg != "whip"
   && arg != "armor"
   && arg != "dun"))
    return notify_fail(CYN"���μǿ�ܵ����Բ�ס����Ҫ�Ķ���������û�С�\n"NOR);
    if(count[arg]>=total)
	return notify_fail(CYN"���μǿ�ܵ����Բ�ס����Ҫ�Ķ������Ѿ������ˡ�\n"NOR); 
    if (arg == "body"
     || arg == "head"
     || arg == "feet"
     || arg == "waist")
    {
	if (me->query_temp("mark/jjf_armor") >=4)
	    return notify_fail(CYN"���μǿ��ŭ������Ҫ����ô����¼ף�����������\n"NOR);
	me->add_temp("mark/jjf_armor", 1);
    }
    else
    {
	if (me->query_temp("mark/jjf_weapon") >= 3)
	    return notify_fail(CYN"���μǿ��ŭ������Ҫ����ô�������������������\n"NOR);
	me->add_temp("mark/jjf_weapon", 1);
    }
    count[arg]+=1;
    if (arg== "bow") {
        obj=new("/d/obj/weapon/archery/mugong");
        obj->set("no_sell", 1);
        obj->set("no_drop", 1);
        obj->set("no_give", 1);
	obj->set("jjf_weapon", 1);
        command("say ��λ"+RANK_D->query_respect(me)+"��"+obj->query("name")+"Ϊ�����࣬ǧ�������ӡ�");
	command("say Ҫ����������Ҫ���뻹(huan)���ҡ�");
        message_vision("���μǿ�ܸ�$Nһ"+obj->query("unit")+obj->query("name")+ "��\n", me);
        obj->move(me);
    }
    else if (arg == "body"
     || arg == "head"
     || arg == "feet"
     || arg == "waist") {
        obj=new(__DIR__"obj/"+arg);
        obj->set("no_sell", 1);
        obj->set("no_drop", 1);
        obj->set("no_give", 1);
	obj->set("jjf_armor", 1);
        command("say ��λ"+RANK_D->query_respect(me)+"��"+obj->query("name")+"Ϊ�����࣬ǧ�������ӡ�");
	command("say Ҫ����������Ҫ���뻹(huan)���ҡ�");
        message_vision("���μǿ�ܸ�$Nһ"+obj->query("unit")+obj->query("name")+ "��\n", me);
        obj->move(me);
    }
    else {
	obj=new(__DIR__"obj/"+arg);
        obj->set("no_sell", 1);
        obj->set("no_drop", 1);
        obj->set("no_give", 1);
	obj->set("jjf_weapon", 1);
        command("say ��λ"+RANK_D->query_respect(me)+"��"+obj->query("name")+"Ϊ�����࣬ǧ�������ӡ�");
	command("say Ҫ����������Ҫ���뻹(huan)���ҡ�");
        message_vision("���μǿ�ܸ�$Nһ"+obj->query("unit")+obj->query("name")+ "��\n", me);
        obj->move(me);
    }

    return 1;
}

string try_me()
{
  command("say ��ʦ�������Ʒѣ�׼����һЩ�������¼ס�");
  return ("ֻҪ�Ǵ����Ҫ�Ϳ�����һ��ȥ�á�");
}

int do_huan(string arg)
{
	object me=this_player(), npc=this_object(), ob;

	if(!objectp(ob=present(arg, me)))
		return notify_fail("������û������������\n");
	if(ob->query("jjf_weapon")==1) {
		message_vision("$N�ó�" + ob->short() + "��$n��\n", me, npc);
		command("say ����������"+ob->query("unit")+ob->query("name")+"���޻������á�");
		command("thank "+me->query("id"));
		destruct(ob);
		me->add_temp("mark/jjf_weapon", -1);
	}
	else if(ob->query("jjf_armor")==1) {
		message_vision("$N�ó�" + ob->short() + "��$n��\n", me, npc);
		command("say ����������"+ob->query("unit")+ob->query("name")+"���޻������á�");
                command("thank "+me->query("id"));
                destruct(ob);
                me->add_temp("mark/jjf_armor", -1);
	}
	else
		return notify_fail(CYN"���μǿ�ܵ����Բ�ס����������ҷ��Ķ����ɣ�\n"NOR);

	return 1;
}

