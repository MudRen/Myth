

#include <ansi.h>
inherit ROOM;
inherit "/d/9ct/qy/climbtree.c";

void create ()
{
  set ("short", HIW"��������"NOR);
  set ("long", @LONG


�� *     .     *             ��  �� *     .    
�����ǻ���������ı���֮��
   ��.         *          ��             ��
�޾������ˣ����ú��ۺþ�.........
           ���������ˣ���Ը������.......��
                 *                        *         
�ǰ������Ҹ������ˣ����ǹ����������أ�
                Ω�м������˼���Ѱ��......
          ��                             ��




LONG);

  set("exits", ([
           "west" : __DIR__"tian1",
//           "east" : __DIR__"yanyang",
      ]));

  set("objects", ([
           "/d/wizz/junhyun/usr/yanyang.c" : 1,
      ]));

  setup();
}
