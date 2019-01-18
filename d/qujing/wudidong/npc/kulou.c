// kulou.c ����
// created 9-15.97 pickle

/************************************************************/
// global declaractions etc.

#include <ansi.h>
inherit NPC;

int accept_object(object me, object ob);
/************************************************************/

void create()
{
  set_name("����", ({"ku lou", "yao", "kulou", "skeleton", "monster"}));
  set("long","��������һ���ɿݵĺ��ǣ�����֪��ô����Ȼ�ǻ�ģ�\n");
  set("gender", "����");
  set("age", 20+random(15));
  set("attitude", "peaceful");
  set("combat_exp", 100000);
  set("daoxing", 50000);

  set_skill("unarmed", 100);
  set_skill("parry", 100);
  set_skill("dodge", 100);
  set_skill("blade", 100);
  set_skill("kugu-blade", 100);
  map_skill("blade", "kugu-blade");
  map_skill("parry", "kugu-blade");
  map_skill("dodge", "kugu-blade");
  set("chat_chance", 1);
  set("chat_msg", ({
	"���õ�������Ҳ��֪������˯�˶���ˡ�\n",
	"���õ���������������ʲôζ���ˡ�\n",
	}) );
  set("inquiry", ([
	"name":		"���֣�ʲô���֣�����Ͳ��ǵ��ˡ�",
	"here":		"��������Ǹ��ƶ���Ҫ�����Ǹ�������ë������ҿ��ţ������ȥ�����⣬���帣�ˣ�",
	"rumors":	"�ٺ٣��Ҷ�������˯��ô�����ˣ�����֪����ʲô��",
	"����":		"�����ܳ��ϵ�����ͺ��ˡ�",
	]));

  setup();
  carry_object("/d/obj/weapon/blade/blade")->wield();
}

/************************************************************/

void init()
{
    object ob;
    ::init();

    if (interactive(ob=this_player()) && !is_fighting())
    {
	remove_call_out("greeting");
	call_out("greeting", 1, ob);
    }
}

void greeting(object me)
{
    string myrude=RANK_D->query_rude(me);
    command("hehe "+me->query("id"));
    command("say ����"+myrude+"����ʲô���ǲ��Ǵ��ö���Т�������ţ�");
    return;
}
/************************************************************/
int accept_object(object me, object ob)
{
    if (ob->query("name_recognized") == "�������")
    {
//	if (!me->query_temp("wudidong/received_renroubao"))
//	{
//	    message_vision(CYN"����������ü�����ⶫ�����ĸ����ģ�ζ�����ԣ�\n"NOR, me);
//	    return 2;
//	}
	command("say ��������С�ӹ�Ȼ��û�����ң�");
	me->add_temp("wudidong/gave_bookguard_baozi", 1);
	return 1;
    }
    command("say ʲô���ã�");
    return 0;
}
/************************************************************/

void die()
{
    string msg;

    msg="����ɢ��һ�Ѱ׹ǣ����˿�ȥ��\n";
    msg+=CYN"����˷����������Ц����ɱ��һ�߿ݹǣ������ǳ������룡�һ�����ģ�\n"NOR;
    if(environment())
	message("vision", msg, environment());
    destruct(this_object());
}
�