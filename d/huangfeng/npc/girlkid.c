// created by angell 1/1/2001
// room: /d/qujing/huangfeng/npc/girlkid.c

inherit NPC;

void create()
{
       set_name("СŮ��", ({ "kid","tong","nu tong","boy" }));
       
set("long","���Ӵ����ɰ��������Ŵ����������أ�\n");
       set("gender", "Ů��");
       set("age", 10);
	   set("per",28);
       set("attitude", "peaceful");
       set("shen_type", 1);
set("combat_exp", 237);
setup();
add_money("coin", 10);
}
