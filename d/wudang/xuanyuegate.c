//Room: xuanyuegate.c ������
//Date: Sep 22 1997

inherit ROOM;
//#include <ansi.h>

void create()
{
      set("short","������");
      set("long",@LONG
�����ǰ��һ����ľ��ï�ĸ�ɽ������ɽ������������Լ�ɼ���һ��ʯ
����ɽ�����죬���ż�������͡�һ������������¥ʽ��ʯ����ɽ��������
�����С������������ĸ����֣�ԭ������������������䵱ɽ���䵱ɽһ��
̫��ɽ��Ϊ��ʮ������֮һ���ж�ʮ�߷塢��ʮ���ҡ���ʮ�Ľ�����̨����
������̶�������š��������һ���أ�����������ɭ�ޣ����ղ��죬������
����
LONG);
      set("objects", ([
                __DIR__"npc/wulei": 1,
      ]));
      set("outdoors", "wudang");
      set("exits",([ /* sizeof() == 1 */
          "northeast": __DIR__"jiejianyan",
          "southup"  : __DIR__"haohanpo",
      ]));
      setup();
}
