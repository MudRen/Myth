/***************************************
MUDLIB��Biographies         ����մ���  
Created Admin By Waiwai@2001/02/18
Admin Email��wkzstory@21cn.com         
****************************************/
// Update by waiwai@2001/04/17

inherit NPC;

void create()
{
	set_name("������", ({"dong fugui", "dong", "boss"}));
	set("title", "�ϰ�");
	set("gender", "����");
	set("age", 35);
	set("kee", 350); 
	set("max_kee", 350);
   set("combat_exp",10000);
   set("daoxing",10000);
	set("sen", 200);
	set("max_sen", 200);	
	set("combat_exp", 10000);
	set("attitude", "friendly");
	set("env/wimpy", 50);
	set("chat_chance", 10);

	set_skill("unarmed", 40);
	set_skill("dodge", 40);

	setup();
        carry_object("/d/obj/cloth/choupao")->wear();

	add_money("silver", 1);
}


