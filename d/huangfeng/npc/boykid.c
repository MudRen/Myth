// created by angell 1/1/2001
// room: /d/qujing/huangfeng/npc/boykid.c

inherit NPC;

void create()
{
       set_name("С�к�", ({ "kid","tong","nan tong","boy" }));
       
set("long","���ӹ��������������Ŵ����������أ�\n");
       set("gender", "����");
       set("per",28);
	   set("age", 10);
       set("attitude", "peaceful");
       set("shen_type", 1);
set("combat_exp", 237);
setup();
add_money("coin", 10);
}
