inherit NPC;

void create()
{
       set_name("��ʿ", ({"wushi", "shi"}));

set("long","һ�����ſ��׵Ĵ�Ϻ�ף���������ȥά������\n");
       set("gender", "����");
       set("age", 20+random(5));
	set("per", 10);
	set("str", 22);
       set("attitude", "heroism");
       set("shen_type", 1);
        set("combat_exp", 60000);
  set("daoxing", 60000);

        set_skill("parry", 60);
        set_skill("dodge", 60);
	set_skill("unarmed", 60);
	set("force", 200);
	set("max_force", 200);
        set("force_factor", 5);
	set("max_kee", 500);
	set("max_sen", 400);
        setup();
        carry_object("/d/obj/armor/tiejia")->wear();

}

�