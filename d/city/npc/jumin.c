/***************************************
MUDLIB��Biographies         ����մ���  
Created Admin By Waiwai@2001/02/18
Admin Email��wkzstory@21cn.com         
****************************************/
// Update by waiwai@2001/04/17

inherit NPC;

void create()
{
	set_name("����",({ "jumin" }) );
        set("gender", "����" );
        set("age", 33);
	set("long", "һλ�������ӣ�������Խ��ʮ���ꡣ\n");
	set("str", 17);
        set("dex", 16);
        set("con", 15);
        set("int", 17);
        set("combat_exp", 10000);
	set("attitude", "peaceful");

        setup();

       carry_object("/d/obj/cloth/linen")->wear();
}

