/***************************************
MUDLIB��Biographies         ����մ���  
Created Admin By Waiwai@2001/02/18
Admin Email��wkzstory@21cn.com         
****************************************/
// Update by waiwai@2002/12/05

#include <ansi.h> 
inherit NPC;

void create()
{
        set_name("��ʦ", ({ "biao shi", "biao", "shi" }));
        set("gender", "����");
	set("title","��"HIR"��Զ�ھ�"NOR"��"); 
	set("long", "�ھ��е���ʦ�����İ����Բ���������������������ӡ�\n");
        set("age", 29);
	set("str", 30);
	set("con", 30);
        set("combat_exp", 30000);
	set("max_kee", 500);
	set("force", 100);
	set("max_force", 100);
	set("force_factor", 5);
        set("shen_type", 1);
	set("attitude", "heroism");
        set_skill("unarmed", 50);
        set_skill("parry", 50);
        set_skill("dodge", 50);
	set_skill("force", 50);

        setup();
        carry_object("/d/obj/cloth/linen")->wear();

}

