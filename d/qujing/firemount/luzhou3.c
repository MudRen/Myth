// rewritten by snowcat on 4/11/1997
// room: luzhou3

inherit ROOM;

void create ()
{
  set ("short", "ɳĮ����");
  set ("long", @LONG

�����ļ����ȣ�Զ������������ľ��󡣲�����Ȼˮ�ݷ��������
�������ա����ذ��հ�����ҵ����Ҳ��Ȼ�Եá��Ա߻���һС����
����Ϊ��ȡˮ�ġ�

LONG);

  set("exits", ([
        "southeast" : __DIR__"qujinglu",
        "west"      : __DIR__"luzhou2",
      ]));
  set("outdoors", "firemount");
  set("resource", ([
        "water" : 1,
      ]));

  setup();
}
