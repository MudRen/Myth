#include <ansi.h>
inherit NPC;

int give_gift(object who);
int clear_xue(object who);

void create()
{
	set_name(HIR"ʥ������"NOR, ({ "shengdan laoren", "old man", "man"}) );
	set("long", "��˵�л��׺��ӵ�ʥ�����ˣ�ר�Ÿ������ʥ������ġ�\n");
	set("attitude", "friendly");
	set("class", "xian");
	set("age", 10000);
	set("max_gin", 2000);
	set("max_kee", 5000);
	set("max_sen", 3000);
	set("max_mana", 3000);
	set("max_force", 5000);
	
	set("str", 30);
	set("per", 20+random(15));

	set("combat_exp", 100000);
	set("daoxing", 3000000);
	set_skill("parry", 300);
	set_skill("dodge", 300);
	set_skill("unarmed", 300);
	set_skill("changquan", 300);
	set_skill("force", 300);
	set_skill("spells", 300);
	set_skill("dao", 300);
	map_skill("unarmed", "changquan");
	map_skill("spells", "dao");

	setup();

	carry_object("/d/wiz/obj/cloth")->wear();
	carry_object("/d/wiz/obj/pixue")->wear();
	carry_object("/d/wiz/obj/bonnet")->wear();
}

void init()
{       
	object ob;
        if(!clonep()) return;

	::init();

        set("chat_chance", 10);
        set("inquiry", ([
                "name" : "����ʥ������Ŷ��\n",
                "here" : "��ط��ҿ���ͷ����Ŷ��\n", 
            "ʥ����" :  (: give_gift :),
            "ʥ������" : (: give_gift :),
            "����" : (: give_gift :),
            "gift" : (: give_gift :),
            "xmas" : (: give_gift :),
            "chrismas" : (: give_gift :),
            "clear" : (: clear_xue :),
         ]) );

        set("chat_msg", ({
		"�����е���������ŨŨ�Ľ�������...\n",
            "ʥ������΢Ц��ף����ң�ʥ������!\n",       
		"�����ʥ���ں�����������Ŷ...\n",
            "ʥ������΢Ц��ף����ң�Merry Chrismas!\n",       
        }) );


                call_out("greeting", 1);
}

int give_gift(object who)
{
	who=this_player();
	if (!userp(who))
	{
		command("maoli "+who->query("id"));
		command("say С������ʥ�����ְ���");
		return 1; 
	}
	if (who->query("yudian/xmas")=="got")
	{
		command("say ʥ�����ְ�����æ���أ�����Ŷ��");
		return 1;
	}
	command("smile "+who->query("id"));
	command("say ʥ������!");
	who->add("combat_exp",10000);
	who->add("daoxing",10000);
	who->add("potential",10000);
	who->add("rsg_eaten",2);
	who->set("yudian/xmas","got");
	write(HIM"����"HIG"��Ե"HIY"��ף��"HIR"ʥ������!\n"
	HIY"������һ��"HIR"ʥ�������:\n"
	HIY"1. Ǳ      ��:   10,000  ��\n"
	HIY"2. ��      ѧ:   10,000  ��\n"	
	HIY"3. ��      ��:       10  ��\n"	
	HIY"4. �˲ι���¼:   �� ��  2��\n"	
      "                "HIM"����"HIG"��Ե"HIY"��ʦ��\n"NOR,who);
	return 1;
}


void greeting()
{
//		command("chat ���λ����ջ��¥��ȡʥ�����лл��");
        message("channel:chat",HIM+"������ʥ����ʥ������(Shengdan Laoren)��"
        +"���λ����ջ��¥��ȡʥ�����лл��\n"+NOR,
        users());
}

int clear_xue(object who)
{
	who=this_player();
	if (!userp(who))
	{
		command("maoli "+who->query("id"));
		command("say С������ʥ�����ְ���");
		return 1; 
	}
	if (who->query("yudian/xue")=="clear")
	{
		command("say ���Ѿ����������!");
		return 1;
	}

	who->delete("bad");
	who->delete("bad_mudage");
	who->set("yudian/xue","clear");
	command("say �ð�!�ҾͰ���һ��!");
	return 1;
}