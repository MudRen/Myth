inherit ROOM;

#include <ansi.h>

void create ()
{
  set ("short","���ϸ��¥����㡪��ĵ��ͤ");
  set ("long", YEL@LONG





                       ��  ��  ĵ  ��  ͤ


                  �������Ʊ�׺˪�����ж��ʵ�Ⱥ��
                  
                  ÷ױ��������ů������ҡ��������

                  ���������ռ�Ӱ��¶�����������

                  ����������徲���������ѩ˪��


                  ��ʱ���ղ���Ũ��Ҷ�ʳ���ʼ�ź�

                  ����Զ�ֽ���¶��ĺ���������÷�

                  ��������ǧ��󣬹����ϸ������

                  �������ɺ����䣬ĺϼ�δ�������




LONG NOR);

  set("exits",([
  "up" : __DIR__"qingfenglou6",
  "enter" : __DIR__"huiyi",
//  "north" : "d/club/qingfeng/wuguan1",
  "down" : __DIR__"qingfenglou4",
  ]));
//set("objects", ([ __DIR__"" : 1, ]));
        set("no_fight", 1);
        set("no_magic", 1);
  set("outdoors", 0);
  set("no_clean_up", 1);
  setup();
}
