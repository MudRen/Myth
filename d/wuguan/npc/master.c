//Cracked by Roath
// master.c ����
// writen by kittt

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("�Ϲ�����" , ({ "wuguan master", "shangguan", "yunzheng","master" }) );
	set("gender", "����");
	set("title", HIC"������ݹ���"NOR);
	set("nickname",HIR"Ѫ���޺�--ǧ��ն"NOR);
	set("age", 48);
	set("long",
		"������������ݵĹ����Ϲ��ƣ����꽭���Ϻų�\n"
		"Ѫ���޺�--ǧ��ն�����ڽ�����ȴ�Ѻ�������֪\n"
		"����������������������ͨͨ��ü��֮�����һ\n"
		"��Ӣ�������˲���������������֮�С�\n");
	set("attitude", "friendly");
	set("shen_type", 1);
 
	set("qi",2500); 	
	set("max_qi", 2500);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 100);
	set("combat_exp", 800000);
	set("score", 20000);
	set_skill("force", 140);
	set_skill("strike", 140);
	set_skill("hammer", 100);
	set_skill("kunlun-zhang", 180);
	set_skill("xuantian-wuji", 160);
	set_skill("kunlun-shenfa", 160);
	set_skill("dodge", 140);
	set_skill("parry", 140);
	map_skill("dodge", "kunlun-shenfa");
	map_skill("parry", "kunlun-zhang");
	map_skill("force", "xuantian-wuji");
	map_skill("strike", "kunlun-zhang");
	prepare_skill("strike","kunlun-zhang");
	set("inquiry",  ([
		"����":	"����С����ȥ�����ܹܾ����ˡ�",
		"����" : "�������ʲô����ȥ�����ܹܰɣ����ᰲ����ġ�",
		"����" : "������ݱ��û�У�����ĵط��ɲ��١�",
		"ѧϰ" : "����������Ӧ��ȥ����������",
        "ǧ��ն" : "�Ƕ���������ʱ��ʤ���µ�ԩ������Ҫ�����ˡ�\n",
		]));
	set("str", 30);
    set("int", 30);
    set("con", 30);
    set("dex", 30);
    set("per", 27);
    set_temp("apply/sword",80);
	
	setup();

	carry_object(__DIR__"obj/cloth")->wear();
	carry_object(__DIR__"obj/changjian")->wield();
}

void init()
{
	object ob=this_player();
	::init();
	
	if (interactive(ob) && !is_fighting() && !wizardp(ob))
	{
		if((int)ob->query("combat_exp") > 20000)
		{
			command("say �ף�������ô�����ģ���ȥ��ȥ�� \n");
			command("kick "+ob->query("id"));
			ob->delete("wuguan");
			ob->delete_temp("wuguan");
			command("say ��һ���и����ã�������ƨ�����ϣ�ƽɳ����ʽ��");
			ob->move(CITY_OB("wuguan","wuguangate"));
            tell_room(environment(ob), "ֻ������~~��һ����У�"+ob->name()+"�����ǰԺ���˹�����ƨ���ϻ�����һ��Ьӡ��\n", ({ ob }));
		}
		if((int)ob->query_condition("killer"))
		{
			command("say �㾹�������ɱ�ˣ�������ǧ��ն��������ô��\n");
            command("consider "+ob->query("id"));
            kill_ob(ob);
		}
	}
}
