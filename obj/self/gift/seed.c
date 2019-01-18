// Update by aeddy@2003/04/25

#include <ansi.h>

inherit ITEM;

string *dirs = ({
"/d/city/",
"/d/westway/",
"/d/kaifeng/",
"/d/lingtai/",
"/d/moon/",
"/d/gao/",
"/d/sea/", 
"/d/jz/", 
"/d/nanhai/", 
"/d/eastway/",
"/d/ourhome/honglou/", 
"/d/xueshan/",
"/d/qujing/wuzhuang/", 
"/d/qujing/baotou/", 
"/d/qujing/baoxiang/", 
"/d/qujing/bibotan/",
"/d/qujing/biqiu/",
"/d/qujing/chechi/",
"/d/qujing/dudi/",
"/d/qujing/fengxian/",
"/d/qujing/firemount/",
"/d/qujing/heifeng/",
"/d/qujing/huangfeng/",
"/d/qujing/heishui/",
"/d/qujing/jilei/",
"/d/qujing/jindou/",
"/d/qujing/jingjiling/",
"/d/qujing/jinping/",
"/d/qujing/jisaiguo/",
"/d/qujing/kusong/",
"/d/qujing/liusha/",
"/d/qujing/maoying/",
"/d/qujing/nuerguo/",
"/d/qujing/pingding/",
"/d/qujing/pansi/",
"/d/qujing/tongtian/",
"/d/qujing/qilin/",
"/d/qujing/qinfa/",
"/d/qujing/qinglong/",
"/d/qujing/sanda/",
"/d/qujing/shuangcha/",
"/d/qujing/tianzhu/",
"/d/qujing/wudidong/",
"/d/qujing/wuji/",
"/d/qujing/xihai/",
"/d/qujing/xiaoxitian/",
"/d/qujing/yingjian/",
"/d/qujing/yinwu/",
"/d/qujing/yuhua/",
"/d/qujing/yunzhan/",
"/d/qujing/zhujie/",
"/d/qujing/zhuzi/",
"/d/penglai/"
});

void create()
{
        set_name(HIY"ҡǮ������"NOR, ({ "seed"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","һ��СС�����ӡ�\n");
                set("unit", "��");

        }
        setup();
        call_out("need_water", 3);
}

void init()
{
        object me = this_player();
        object env = environment();

        if( env != me ) return;

        remove_call_out("need_water");
        call_out("need_water", 10 + random(5));
        add_action("do_water", "water");
}

void need_water ()
{
        object who = environment();
        string msg;

        if( !who || !living(who) )
                return;

        if( query("dried")) return;

        if( query("id") == "seed") {
                call_out ("need_water",3);
                return;
        }

        switch( query("water") ) {
                case 0:
                         msg = name(1) + "������һ�㡣\n";
                         break;
                case 1:
                         msg = name(1) + "�е����ˣ�����һ��ˮ�ɡ�\n";
                         break;
                case 2:
                         msg = name(1) + "��ʼ�����ˡ�\n";
                         break;
                case 3:  
                         msg = name(1) + "�Ѿ�ʧȥ����ɫ�Ĺ���\n";
                         break;
                case 4:  
                         msg = name(1) + "����ȥ����ȱˮ������һϢ�ˡ�\n";
                         break;
                default: msg = name(1) + "�ɿ��ˡ�\n";
                         set("name","��" + name(1));
                         set("dried",1);
                         break;
        }
        message_vision(msg,who);
        set("water", query("water")+1);
        call_out ("need_water",random(10)+10);
        remove_call_out ("grow");
        call_out ("grow",random(5)+5);
}

int do_water (string arg)
{
        object who = this_player();
        string msg;

        if (arg != query("id"))
                return 0;

        if (query("water") >= 5) {
                message_vision ("$N����ˮһ�ε�����" + name(1) + "�ϡ�\n",who);
                return 1;
        }

        if (who->query("kee")>10)
                who->add("kee",-10);
        else {
                who->unconcious();
                return 1;
        }

        switch (random(9)) {
                case 0:
                         msg = "$N�ں���ˮ������" + name(1) + "�ϡ�\n";
                         break;
                case 1:
                         msg = "$N��һ����ˮ����" + name(1) + "�ϡ�\n";
                         break;
                case 2:
                         msg = "$N�����ץסϸϸ��С�꣬����" + name(1) + "�ϡ�\n";
                         break;
                case 3:
                         msg = "$NС�ĵ�����һ���¶ˮ������" + name(1) + "�ϡ�\n";
                         break;
                case 4:
                         msg = "$Nһ����ʹ����ˮ����" + name(1) + "�ϡ�\n";
                         break;
                case 5:
                         msg = "$N˫������" + name(1) + "���쵽�����С���С���\n";
                         break;
                case 6:
                         msg = "$N��ϸ������һֻС���ӣ���ˮ����" + name(1) + "�ϡ�\n";
                         break;
                case 7:
                         msg = "$N�����Ұ������ĳ�¶������" + name(1) + "�ϡ�\n";
                         break;
                case 8:
                         msg = "$N����ָպ����ˮ��һ������" + name(1) + "�ϡ�\n";
                         break;
        }

        message_vision (msg,who);
        set("water",0);
        remove_call_out ("grow");
        call_out ("grow",random(5)+5,who);
        return 1;
}

void grow ()
{
        object who = environment();
        string msg;

        if (! living(who))
                return;

        if (query("dried")) return;

        if (query("id") == "seed") {
                if (random(3) == 0) {
                        message_vision ("�������ѿ���¶����һ����ѿ��\n",who);
                        set_name("��ѿ", ({ "germ"}));
                        set("long","һ�����ڳ����С��ѿ��\n");
                        set("unit", "��");
                } else message_vision ("���Ѷ���һ�£��ʹ���һ��㡣\n",who);
                return;
        }

        if (query("id") == "germ") {
                if (random(6) == 0) {
                        message_vision ("��ѿ���ڳ����ˣ��ڷ��л����ҡ߮��\n",who);
                        set_name("����", ({ "plant"}));
                        set("long","һ����׳�����磬���滹��Щϸ֦��\n");
                        set("unit", "��");
                } else message_vision ("��ѿ����һ��������һ�ء�\n",who);
                return;
        }

        if( query("id") == "plant" )  {
                if (random(12) == 0) {
                        object flower;
                        message_vision ("�������ڳ���һ��"HIY"���Ӳ�"NOR"�Ĵ����ˣ�֦Ҷ�ϵĽ����ڷ��л����ҡ߮��\n",who);
                        flower = new (__DIR__"goldmine.c");
                        flower->set("name", who->name(1) + "��" + flower->name(1));
                        message("system",
                                WHT"��"HIR"С����Ϣ"NOR WHT"����˵" + flower->name() + WHT"��"+ MISC_D->find_place(environment(who))+
                                filter_color(environment(who)->query("short")) + NOR WHT "�����ˡ�\n"NOR, users());
                        flower->set("seed_water",log_id(who));          
                        flower->move(environment(who));
                        destruct(this_object());
                } else {
                        switch (random(3)) {
                                case 0:
                                        message_vision ("�����ڷ����������衣\n",who);
                                        break;
                                case 1:
                                        message_vision ("����Ҫ�����ˡ�\n",who);
                                        break;
                                case 2: message_vision ("����΢Ц�š�\n",who);
                                        break;
                        }
                }
        }
}

void create_seed()
{
        string dir, name;
        mixed  *files, *rooms;
        object env;

        dir = dirs[random(sizeof(dirs))];

        files = get_dir(dir,-1);

        rooms = files[random(sizeof(files))];

        while(rooms[1] == -2
        || rooms[1] <= 0 
        || (  !objectp( env = find_object(dir + rooms[0]) ) 
           && !objectp( env = load_object(dir + rooms[0]) ) ) )
                rooms = files[random(sizeof(files))];

        this_object()->move(env);

        name = MISC_D->find_place(env);
        tell_room(env, HIY"ֻ����ž����һ����һ��������������ӵ�������ĸ�ǰ��\n"NOR);
        message("channel:sys", HIW"������ҡǮ�����ӵ����� [" + dir + rooms[0] +"]\n"NOR, users());
        message("system",
        WHT"��"HIR"С����Ϣ"NOR WHT"����˵һ�Ž�����������Ӵ�"HIG"����"NOR WHT"�����˼䣬�ƺ�����" + name + WHT"��\n"NOR, users());

}