//create by smile 12/8/98
// room: /d/qujing/baigudong/shanshipo.c

inherit ROOM;

void create ()
{
  set ("short", "ɽʯ��");
  set ("long", @LONG

    �����߳���ɽʯ·�����۶�ȥ��һƬ�����ƽ��ɽ���
����ԶԶ����ɽ�ͣ�ɽ���¶Ȳ������ߵ�ɽ���ﶼ�Ѹ�
�ѣ�����ȷʵ���ȡ�����ɽ���Ͼ����ģ��������գ�����
�ĸ�����,��Լ�������˺�������

LONG);

  set("exits", ([
        "westdown"       : __DIR__"xiapolu1",
        "northeast"  : __DIR__"sroad7",
      ]));
  set("objects", ([
        __DIR__"obj/baigu"   : 1,
      ]));
  set("outdoors",__DIR__"");

  setup();
}

int valid_leave (object who, string dir)
{
  object where = this_object ();

   who->set_temp("obstacle/east_from",1);
  if (who->query("obstacle/baigudong")=="done")
         return ::valid_leave (who, dir);
 
  if (dir == "northeast")
    return ::valid_leave (who, dir);

  if (who->query_temp("obstacle/baigudong_nuzi_killed") == 0)
  {
    if (! present ("nu zi",where))
    {
      object ob = new (__DIR__"npc/nuzi");
      ob->move(where);
     return notify_fail("ͻȻһ���ҽУ�һ������Ů�Ӵ�ɽ���Ϲ�������������������¡�\n");
    }
    return notify_fail("����Ů�ӳ�ס��Ľţ��������ߡ�\n");  
  }
  if (who->query_temp("obstacle/baigudong_furen_killed") == 0)
  {
    if (! present ("fu ren",where))
    {
      object ob = new (__DIR__"npc/furen");
      ob->move(where);
       return notify_fail("����ǰ��Ӱһ�Σ�һλ�������ϸ�����ס���㡣\n");
    }
      return notify_fail("�ϸ�����ס����,�������ߡ�\n");
  }
  if (who->query_temp("obstacle/baigudong_gonggong_killed") == 0)
  {
    if (! present ("gong gong",where))
    {
      object ob = new (__DIR__"npc/gonggong");
      ob->move(where);
    return notify_fail("��Ȼ����һ����̾��һλ�׷��ԲԵ��Ϲ�����������ǰ��\n");
    }
    return notify_fail("�Ϲ�����ס�㣬�Ͳ������ߡ�\n");
  }
  return ::valid_leave (who, dir);
}
