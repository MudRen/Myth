//Cracked by Roath
//standroom.c used by weiqi...others may hate this format:D
//chufang.c

#include <room.h>
inherit ROOM;
//#include <ansi.h>

int do_add(string);
int do_jian(string);
int do_make_ice(string);

int temperature;

void create ()
{
	set ("short", "����");
	set ("long", @LONG

������ѩɽ�ɵĳ�����ѩɽ�����Ը��ײ��߼��࣬��������֮��
���̻�����������ﾭ����������ӽ��䴦����һ�ڴ�����(guo)��
��ѩɽ���������õģ��Ա߻���һ���״���(pen)��
LONG);

	set("item_desc", 
        (["guo" : 
             " һ�ڴ�������������Ӷ�����(add)����ҩ��(jian yao)��\n", 
          "pen" : 
             "һֻ�״��裬����ʢ������ˮ��Ҫ���Ʊ�(make_ice)�����Ϳ����ˡ�\n", 
        ]));


	set("exits", 
	([ //sizeof() == 4
		"west" : __DIR__"shanpo",
	]));
	
	set("objects", 
	([ //sizeof() == 1
                "/d/obj/food/xueli" : 3,
                "/d/obj/food/zongzi" : 1,
	]));

        set("resource", ([ /* sizeof() == 1 */
         "water" : 1,
         ]));

        create_door("west", "������", "east", DOOR_CLOSED);
        set("no_clean_up", 0);

        set("cook/allow",0);
        set("cook/shui",0);
        set("cook/she",0);
        set("cook/wugong",0);
        set("cook/zhizhu",0);
        set("cook/hama",0);
        set("cook/xie",0);

	setup();
}


void init()
{                                             
        add_action("do_make_ice", "make_ice");
        add_action("do_add", "add");
        add_action("do_jian", "jian");
}

int do_add(string arg)
{
        string item_name;
        object who = this_player();
        object me = this_object();
        object item;

        if(!arg) return notify_fail("��Ҫ��ʲô�����ӽ����\n");
        if( sscanf(arg, "%s in guo", item_name)!=1 )
                return notify_fail("�÷���add <> in guo��\n");

        if (item_name=="water")
          {
          message_vision( "$N������Ҩ��һ��ˮ��\n",who);
          me->set("cook/allow",1);
          me->set("cook/shui",1);
          return 1;
          }

        item=present(item_name, who);
        if (! present(item_name, who)) return notify_fail("������û���ⶫ����\n");

        if ( item->query("cook/allow") !=1 ) 
        return notify_fail("�����������ҩ�ģ���ʲô�����������ӡ�\n");
        if ( item->query("cook/type") == "shui") me->set("cook/allow",1);
        message_vision( "$N��һ"+item->query("unit")+item->query("name")+"�ӽ����\n",who);
        set("item_desc/guo" , " һ�ڴ�����(add)����ҩ��(jian yao)��"
             +"�������߰���Ĳ�֪����Щʲô��\n");

        if (me->query("cook/"+item->query("cook/type")) < item->query("cook/value"))
           me->set("cook/"+item->query("cook/type"),item->query("cook/value"));
        destruct(item);
        return 1;
}

int do_jian(string arg)
{
        object me = this_object();
        object who = this_player();
        object tang;
        int prices;
 
        if(!arg || arg != "yao") return notify_fail("��ɶ��\n");
        if ( !me->query("cook/allow") ) return notify_fail("������ˮ��û�У���ô�壿\n");

        prices=me->query("cook/shui")*me->query("cook/she")*me->query("cook/xie")
                   *me->query("cook/hama")*me->query("cook/zhizhu")*me->query("cook/wugong");

        tang=new("/d/xueshan/obj/tang");
        if( !prices ) tang->set("name","ˢ��ˮ"); 
        tang->set("prices",prices); 
        message_vision( "$N�ڹ�����ҽ��˽���������һ��"+tang->query("name")+"��\n",who);
        tang->move(environment(who));

        me->set("cook/allow",0);
        me->set("cook/shui",0);
        me->set("cook/she",0);
        me->set("cook/wugong",0);
        me->set("cook/zhizhu",0);
        me->set("cook/hama",0);
        me->set("cook/xie",0);

        set("item_desc/guo" , " һ�ڴ�����(add)����ҩ��(jian yao)��\n");

        return 1;
}


int do_make_ice(string arg)
{
        object me = this_object();
        object who = this_player();
        int ii;

        if (who->query_skill_mapped("force")!="ningxie-force")
                return notify_fail("ֻ���ñ�����Ѫ��������ˮ�ɱ���\n");
        if (who->query("force")<100)
                return notify_fail("���������̣�������������㡣\n");

        temperature=0;
        message_vision("$N�������ʳָ��������衣\n",who);
        who->start_busy(10);
        call_out ("freezing",10,who);
        me->add("force", -100);

        return 1;
}


int freezing (object who)
{
  object bing;
  string *msg = ({
  "ˮ��㸡��һ˿˿������\n",
  "��������ð���ɹɺ�����\n",
  "�����������һ���˪��\n",
  "ˮ����һƬƬ������\n",
  "��Խ��Խ��\n",
});

  temperature=temperature+10;
  if (temperature<200)
    {
     if (who->query("force")<100) 
       {
        message_vision("$N�����죬���е�ˮȴ��û��ɱ���$N�ѹ���վ��������\n",who);
        temperature=0;
        return 1;
       } 
     else 
       {
        message_vision(msg[random(sizeof(msg))],who);
        who->add("force", -100);
        who->start_busy(10);
        call_out ("freezing",10,who);
        return 1;
       }
    }
  else 
    {
    message_vision("һյ��ʱ�֣�һ������ˮ��������һ����ʵʵ��������\n",who);
    bing=new("/d/xueshan/obj/xuanbing");
    bing->move(environment(who));
    return 1;
    } 
}


