/***************************************
MUDLIB��Biographies         ����մ���  
Created Admin By Waiwai@2001/02/18
Admin Email��wkzstory@21cn.com         
****************************************/
// Created by waiwai@2000/10/12
// һ������(arrive)��ȥ(leave)��Ϣ��NPC����
// ��/d/city/npc/xiaoer.c ��die��msg���Ӧ����
// ����ֵ�ϸ�����ø�����ɫ��NPC

inherit NPC;
#include <ansi.h>

void create()
{
    set_name("Сè��", ({ "catty", "cat", "maomi" }) );
        set("race", "Ұ��");
        set("age", 1);
        set("gender", "����");
        set("long", "һֻСС�ģ�èͷè�Ե�С��è��\n");
    	 set("combat_exp", 1000000);
        set("per", 25);
        set("zombie", 1);//��ΪѪˮ������
        set("attitude","peaceful");
        set("limbs", ({ "ͷ��", "����","β��" }) );
    	 set("verbs", ({ "bite","claw" }) );
        set_temp("apply/dodge", 1000);

	 set("chat_chance", 30);
        set("chat_msg", ({
		(: random_move :)
        }) );

        set("lead_to", 1); // �ɸ����־
        set("arrive_msg", "���˹��������ء�����");
        set("leave_msg", "������������һ���������ˡ�");
        setup();
}
