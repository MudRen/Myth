// changan/npc/tiesp.c

inherit NPC;

void create()
{
	set_name("������", ({"tie suanpan", "tie", "zhanggui"}));
	set("title", "Ǯׯ�ƹ�");
	set("gender", "����");
	set("age", 54);
	set("kee", 800); 
	set("max_kee", 800);
	set("sen", 200);
	set("max_sen", 200);	
	set("combat_exp", 50000);
	set("attitude", "friendly");
	set("env/wimpy", 50);
	set("chat_chance", 10);
	set("chat_msg", ({
	"�����̺ٺٺٵ�Ц�˼�������������̼�ʮ�����ɴ���û�����\n",
	"�����̽�����˵��������Ǯׯ���ϰ壬����˵�����˲�������������϶��������졣\n"
	}));

	set_skill("unarmed", 60);
	set_skill("dodge", 60);

	setup();
            carry_object("/d/ourhome/obj/choupao")->wear();
	add_money("gold", 1);
}


