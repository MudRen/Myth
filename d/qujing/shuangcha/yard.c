//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.3
//  /d/qujing/shuangcha/yard.c

inherit ROOM;
#include <ansi.h>

string *msgs = ({
        "�����ᣡһ�����ߣ����ǲ���˵��������֮��̰�����¡�\n",
        "�����ᣡ�����������£���Ӧ̰�����ǹ�˵���ܸ��¡�\n",
        "����ɫ���ң����������ң�������а�������ܼ�������\n",
        "�����ᣡ��������ʵ��������˵�ø��¶ࣻ�Ը����޹ʣ�����˵�ø��¶ࡣ\n",
        "�����ᣡ�����ƺΣ����������۲���\n",
        "���ǣ��������������ۡ�\n",
        "�����ᣡ�����ƺΣ����������۲���\n",
        "���ǣ��������������ۡ�\n",
        "�����ᣡ�����ƺΣ������л��۲���\n",
        "���ǣ����������л��ۡ�\n",
        "�����ᣡ�����ƺΣ������з��۲���\n",
        "���ǣ����������з��ۡ�\n",
        "�����ᣡ�����ƺΣ������з��۲���\n",
        "���ǣ����������з��ۡ�\n",
        "�����ᣡ�����ƺΣ����������ɳ����˵��ɳ����\n",
        "���ǣ���������˵��ɳ��\n",
     });


void create ()
{
  set ("short", "ͥԺ");
  set ("long", @LONG

ͥԺ���漸����Ӷ��æµ�ţ�����������һЩ��ȥ��Ұ�ޣ���
û�����ü���Ƥ������Ѫ���߰ߣ�һ�Ի����������⵶����һ
�����档
LONG);

  set("exits", ([
        "west" : __DIR__"zhengting",
        "north"   : __DIR__"kitchen",
        "south": __DIR__"sleeproom",
        "out" : __DIR__"gate",
      ]));
  set("outdoors","sc");
  set("objects" ,([
        __DIR__"npc/yongren" :3,
        ]));
  setup();

}

void init()
{
        add_action("do_nianjing","nianjing");
}

int do_nianjing ()
{
  object who = this_player();
  int size = sizeof(msgs);
  int i = who->query_temp("sc_can_dream");
  int j;
if (!who->query_temp("sc/taibao_seen")) return notify_fail("û���������,��Ϲ����ʲô��?\n");
  if (who->is_busy())
    return notify_fail ("����æ���أ�\n");

  message_vision ("$N��ϥ���������Ʊ�Ŀ��\n",who);
  if (i >= (size/2))
  {
    message_vision ("\n$N�о�����ľ��Ѿ��㹻���������ˡ�\n",who); 
 who->set_temp("sc_can_sleep",1);
  }  
  else
  {
    j = i*18+10;
    who->start_busy (j,j);
    call_out ("start_nianjing",5,who,i);
    call_out ("finish_nianjing",j,who);
  }
  return 1;
}

void start_nianjing (object who, int i)
{
  message_vision ("\n$N�����"+msgs[i]+"\n",who); 
  who->set_temp("sc_can_dream",i+1);
}

void finish_nianjing (object who)
{
  object where = environment(who);

  who->interrupt_me ();
  message_vision ("\n$N���ϣ�����\n",who); 
  where->add("times",1);
}
