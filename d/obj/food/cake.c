
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("���յ���" , ({"cake"}));
        set_weight(1);
        set("unit", "��");
        set("long", "һ���ô�����͵���,רΪ��ף���ն�����\n");
        set("value",100000);
        set("no_get",1);
        set("no_drop","��ô�óԵĸ⣬�ɲ�������ӣ� \n");
        setup();
}

void init()
{
       
        add_action("do_eat","eat");
        if (!query("owner")) add_action("do_celebrate","celebrate");
        else {
          add_action("do_cut","cut");
          add_action("do_blow","blow");
          add_action("do_wish","wish");
        }              
          
}

int do_eat(string arg)
{
        object me = this_player();
 
        if (!id(arg))
           return notify_fail("��Ҫ��ʲô��\n");
        write(HIW
"��һ���˳���ô��һ�����⣿
�������ˡ�������(cut)�������ų԰ɡ�\n"NOR,me);
        return 1;
}

int do_cut(string arg)
{
        object *alluser,obj,cakepiece;
        int s;
        object me = this_player();
        object room=environment(this_player());
        
        if (query("owner")!=getuid(me))
            return notify_fail("�ֲ���������գ���ҪϹ������\n");
        if (!arg || arg!="cake")
           return notify_fail("��Ҫ��ʲô��\n");
        
        if (!query("blow")) return notify_fail("�ȴ�(blow candle)����\n");
        alluser=users();        
        s=sizeof(alluser);
        message_vision(HIW"$N�Ѵ󵰸��г���"+chinese_number(s)+ 
              "С�顣\n$N�����һ�˷���һС�鵰�⡣\n"NOR,me);

        
        for (int i=0;i<s;i++) {
            obj=alluser[i];
            cakepiece=new(__DIR__"cakepiece");
            cakepiece->move(obj);
            if (obj!=me)
              message("vision",me->query("name")+"����һ�����յ��⡣\n",obj);
        }

        destruct(this_object());
        return 1;
}

int do_celebrate(string arg) {

    object me,obj;
    string msg;
    int space;
    me=this_player();
    if (query("owner")) return 0;
    if (!arg) return notify_fail("��Ҫ��˭��ף���գ�\n");
    if(!objectp(obj = present(arg, environment(this_player()))))
         return notify_fail("����û������ˡ�\n");
    if(!userp(obj))
         return notify_fail("���յĲ��ᣡ\n");
    if (obj==me) 
         write("����Լ�׼����һ�����յ��⡣\n");
    else message_vision("$N��$n˵�������տ��֣���˵�����һ���󵰸⡣\n",me,obj);

    this_object()->move(obj);
    set("owner",getuid(obj));       

    msg= HIR"                () () () () ()\n"+
         HIW"            @@@@"+HIY"|| || || || ||"+HIW"@@@@\n"+
         "           @    "+HIY"|| || || || ||"+HIW"    @\n"+
         "          @@                      @@\n"+
         "          @@";
    space=(14-strlen(obj->query("name")))/2;
    for (int i=0;i<space;i++) msg+=HIG" ";
    msg+=obj->query("name")+"���տ���";
    for (int i=0;i<space;i++) msg+=" ";
    msg+=HIW"@@\n"+
         "          @@    "+HIM"@>-  @>-  @>-     "+HIW"@@\n"+
         "           @    "+HIM"@>-  @>-  @>-     "+HIW"@\n"+
         "            @@@@@@@@@@@@@@@@@@@@@@\n"NOR;
    set("long",msg);   
    this_object()->move(obj);
   
    remove_action("do_celebrate","celebrate"); 
    return 1;
}

int do_wish(string arg) {

    object me=this_player();

    if (!arg) return notify_fail("��Ҫ��ʲ��Ը��\n");
    if (query("owner")!=getuid(me)) notify_fail("�ֲ���������գ���ʲ��Ը��\n");
    
    write("ףԸ"+arg+"\n");
    message_vision("$N����˫�ۣ����������첻֪��˵��Щʲ�ᡣ\n",me); 
  
    set("wish",1);
    remove_action("do_wish","wish");
    return 1;
}

int do_blow(string arg)  {
    object me=this_player();

    if (!arg || arg!="candle") return notify_fail("��ʲ�᣿\n");
    if (query("owner")!=getuid(me)) 
       notify_fail("�ֲ���������գ���ҪϹ������\n");
    if (!query("wish")) return notify_fail("����(wish)��Ը��\n");

    message_vision("$N���������һ�������������һ������Ϩ������\n",me); 
    remove_action("do_blow","blow");
    set("blow",1);
    return 1;
}

