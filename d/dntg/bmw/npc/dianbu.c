 
inherit NPC;
 
void create()
{
	set_name("�䲾", ({"dian bu"})); 
        set("gender", "����" );
	set("long", "�����䲾��\n");
        set("age",40);
	set("title", "�����");
        set("str", 30);
        set("int", 20);
	set("con", 30);
	set("spi", 20);
        set("per", 15);
	set("class", "xian");
	set("attitude", "friendly");
        set("combat_exp", 8500);
  set("daoxing", 8500);

	set("max_kee", 1000);
	set("max_sen", 1000);
        setup();
        carry_object("/d/obj/cloth/xianpao")->wear();
}
 

�