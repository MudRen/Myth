// Room: /u/hkgroup/nonsense
inherit ROOM;

void create ()
{
  set ("short", "��¥");
  set ("long", @LONG

���������β�����˼Ѫ���׺춹��
�������������괺����������¥(painting)

LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "painting" : "
         ����
             һ��̫��
                 ���ڰ��
                     ����
                         ����δ��
                         ����δ��

         ����
             һĨϦ��
                 ��;��·
                     ����
                         ��Ӱ����
                         ������Ϣ

         ��ǰ
             һ���ƻ�
                 ΢��뿪
                     ����
                         ��Ҳ����
                         ��Ҳ����

         ����
             һ֧����
                 �ǻ�����
                     ����
                         ��ϥ����
                         ���۶��

",
]));
  set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"cave",
]));
  set("no_fight", 1);

//  set("objects", ([
//           __DIR__"npc/niu.c": 1,
//]));

  setup();
}
