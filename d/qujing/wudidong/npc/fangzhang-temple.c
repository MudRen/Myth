// fangzhang.c
// created by mes, updated 6-21-97 pickle

#include <ansi.h>
inherit NPC;

void create()
{
  set_name("Բ��",({"yuan qing", "yuan", "qing", "fang zhang", "monk", "yuanqing"}));
  set("title","����");
  set("gender", "����");
  set("age", 80);
  set("long","һ���װ����ֵ��Ϻ��У��������η���ģ����ֱ���������ˡ�\n");
  set("combat_exp",5000);
  set("str",30);
  set("per",30);
  set("int",30);
  set("attitude", "peaceful");
  set("inquiry", ([
		   "name" : "��������������֣�����Բ�塣\n",
		   "��" : "��֪Ϊ�ͣ�Ժ���ǿھ���ʱ���������˹��ˡ��Ĺ�������\n
����û�˻�ˮ������Ҳ�޷���ȥ�������ס�",
		   "ʯ��" : "��֪Ϊ�Σ�Ժ���ǿھ���ʱ���������˹��ˡ��Ĺ�������\n
����û�˻�ˮ������Ҳ�޷���ȥ�������ס�",
		   ]));
  set("chat_chance",2);
  set("chat_msg",({
    "Բ���������˵������Ժ���ʯ������а�ˡ���\n",
 }));
  setup();
  carry_object("/obj/cloth")->wear();
}
void init()
{
  object me;

  ::init();
  if( interactive(me = this_player()) && !is_fighting() ) {
    remove_call_out("greeting");
    call_out("greeting", 1, me);
  }
}
void greeting(object me)
{
  if( !me || environment(me) != environment() ) return;
  say(CYN "Բ����������ϲ������ԭ���Ƕ����ݵ���������������������\n" NOR);
}
 

�
