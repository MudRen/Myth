// ������ by Calvin

#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "�������봦");
  set ("long", @LONG

�����ǰ������봦,�������������˵�����Ѿ��߱��˿������ɵ�����������Ϊ��
����ף���㡣������������������д����������:

          1.���ɴ�ʼ��                 2.��������
          3.���ɸ���ηּ�             4.����εĹ����ֹ�
          5.����������������           6.����������,������,��������ѡ��
          7.����ԭʼ��Ա����           8.���ɻ�ַ
          9.��������                   10.����Ҫ��

LONG);

  set("exits", ([ /* sizeof() == 2 */
                    "west" : "/d/calvin/lanling/xingyuejiulou2",
]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

   setup();
   call_other("/obj/board/clubroom_b","???");
        replace_program(ROOM);
}
