/***************************************
MUDLIB��Biographies         ����մ���  
Created Admin By Waiwai@2001/02/18
Admin Email��wkzstory@21cn.com         
****************************************/
// Update by waiwai@2001/04/17

inherit NPC;

void create()
{
        set_name("��ʦ", ({"fashi"}));
        set("age", 32);
        set("gender", "����");
        set("long","һλ��ʦ��\n");
        set("attitude", "peaceful");
	set("per", 25);
        set("combat_exp", 8000);
	set("force", 200);
	set("max_force", 200);
	set("force_factor", 3);
        set_skill("unarmed", 40);
        set_skill("dodge", 40);
	set_skill("parry", 40);
	set_skill("spells", 100);
        set("chat_chance", 4);
        set("chat_msg", ({
"��ʦ���ﲻ֪������߶Щʲô��������\n",

}) );
	setup();

        carry_object("/d/lingtai/obj/cloth")->wear();
}
int accept_fight(object me)
{
        command("say ̫���Ͼ��������\n");
        return 1;
}

