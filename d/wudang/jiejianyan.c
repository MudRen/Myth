//Room: jiejianyan.c �⽣��
//lpg 19991005

#include <ansi.h>
inherit ROOM;
string look_shibei();

void create()
{
      set("short","�⽣��");
      set("long",@LONG
�����������м���ʢ�����䵱�⽣�ң����½⽣��ˮ�������ˡ�����
��ʿ���˶��Ծ��⽣����ʾ���䵱�ɵ��𾴡�ǧ���������������⡣·��
�߳�������ĺ�������ֻ�ܿ���һ����ա�·���е�ʿ�ڷ�������������
�ɻش����·���и�ʯ��(shibei)��

LONG);
      set("objects", ([
           __DIR__"npc/shejiang": 1,
      ]));
      set("item_desc", ([
          "shibei" : (: look_shibei :),
      ]));
      set("outdoors", "wudang");
      set("exits",([ /* sizeof() == 1 */
          "east"      : __DIR__"songlin3",
          "southwest" : __DIR__"xuanyuegate",
      ]));
//      set("no_clean_up", 0);
      setup();
}

int valid_leave(object me, string dir)
{
        mapping myfam;

        me = this_player();
        if ((me->query_temp("weapon") || me->query_temp("secondary_weapon"))
             && dir == "southwest"
             && objectp(present("teng she", environment(me))))
        {
            message_vision(CYN"�߽��ȵ�������ɫ�˵ȣ����⽣�Ҷ���⽣��ǧ�������������⣡��\n\n$N�����䵱ɽ�棬����Ӳ����ֻ������һ����\n\n"NOR,me);
            me->move("/d/wudang/songlin3");
            return notify_fail(HIR"�벻Ҫװ��������\n"NOR);
         }
        return 1; // mudring changed
}
string look_shibei()
{
        return
        "��������������������������������������������������\n"
        "����������        ��������������������������������\n"
        "����������        ���䵱ɽ��ʾ    ����������������\n"
        "����������                            ������������\n"
        "����������    ��������䵱ɽ�⽣�ҡ����С���������\n"
        "���������������˿����Ծ��⽣��аħ���������������\n"
        "������������ֹ����                ����������������\n"
        "����������������аħ��ʢ��������ή�ң���  ��������\n"
        "����������־�߳�ħ�����Թ����͡�  ����������������\n"
        "������������������                ����������������\n"
        "��������" HIC "����־���룺ask XXX about ��ħ��" NOR "����������\n"
        "������������������                ����������������\n"
        "��������������������������������������������������\n";
}
