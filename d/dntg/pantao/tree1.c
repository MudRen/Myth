#include <ansi.h>
inherit "/d/dntg/pantao/tree.c";

void falldown(object,object);
void create()
{
        set("short", "�������"NOR);
        set("long", "��Χ֦Ҷ��ï��������գ�һƬ�������������������ź�
ͮͮ������������֡�������������罺ˣ���ǧ��һ�졣\n");




        set("exits", ([
  "down": __DIR__"pan1b",
        ]));

        set("objects", ([
               __DIR__"obj/pantao3": 2,
              ]));

        setup();
}


