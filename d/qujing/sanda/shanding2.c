//Cracked by Roath

//  ����֮�� ������
//  by happ@YSZZ 2000.4.14

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "ɽ��");
  set ("long", @LONG

ɽ���Ͼ���Щ�����������Ϳ�������գ�����������л���ĸ質
�ţ��ƺ�������֪���������ϴ��ںܶ��Σ�գ�����һЩС�Ķ���
��������Ľű��ܹ����㲻��ͯ�Ĵ󷢣������Ա߻���һ�ô�������
�������������ȥ������

LONG);

  set("exits", ([
        "southwest": "/d/qujing/baoxiang/yelu8",
        "southeast"     : __DIR__"shanding",
      ]));
  set("objects",([
        __DIR__"npc/gonggong":1,
        ]));
  setup();
}
