// ash.c

inherit ITEM;

void create()
{
        set_name("�ҽ�", ({ "huijin", "ash" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                                set("unit", "��");
                                set("value",0);
                set("long", "һ���޷����ϵĽ��ڵĻҽ�������һ���ƽٺ����µĲ��ࡣ\n");
                }
        setup();
}

void init()
{
   add_action("do_sign","sign");
}

int do_sign(string arg) {
   object me=this_player();
   string str;

   if (arg!="photo") return 0;
   if (query("name")!=me->query("name")+"����Ƭ")
        return notify_fail("��ֹ�ڱ��˵���Ƭ����Ϳ�һ���\n");

   str=query("long");
   str=str+ "��Ƭ����"+me->query("name")+"���ױ�ǩ����\n";
   
   message_vision("$N����Ƭ�����ɷ����ǩ�����Լ��Ĵ�����\n",me);
   set("long",str);
   set("name",me->query("name")+"��ǩ����Ƭ");
   remove_action("do_sign","sign");
   return 1;
}
   

