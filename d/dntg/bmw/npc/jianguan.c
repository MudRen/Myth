 
inherit NPC;
 
void create()
{
	set_name("���", ({"jian guan","guan"})); 
        set("gender", "����" );
	set("long", "������١�\n");
        set("age",20);
	set("title", "�����");
        set("str", 30);
        set("int", 20);
	set("con", 30);
	set("spi", 20);
        set("per", 15);
	set("class", "xian");
	set("attitude", "friendly");
        set("combat_exp", 4000);
  set("daoxing", 4000);

	set("max_kee", 300);
	set("max_sen", 300);
        setup();
        carry_object("/d/obj/cloth/xianpao")->wear();
}
 

�