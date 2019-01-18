// Inheritable Object:/inherit/item/yueqi.c
// Written by jjgod@FYTX.

#include <ansi.h>
inherit ITEM;

string *start_msg=({
        "ֻ��$N�ó�$n��ϸϸ�ĵ��������ң����Ŵ������һҾ��\n",
        "ֻ��$N����$n��̧��ͷ�����Ŵ��΢΢һЦ��\n",
        "$N�ó�$n����ָ���Ღ����һ�����ҡ�\n",
        "$N��Դ�ң��ڿ�$n����ͷע����$n��\n",
        "ֻ��$Nһ��˫�֣�$n�Ѿ�������$N���С�\n",
});

string *end_msg=({
        "ֻ��$N���Ŵ������һҾ������$n��\n",
        "ֻ��$N����$n��̧��ͷ�����Ŵ��΢΢һЦ��\n",
        "$N����$n��˳�����Ღ����һ�����ҡ�\n",
        "$N��Դ�ң�����$n����ͷע����$n��\n",
        "ֻ��$Nһ��˫�֣�$n���Ѿ���ʧ�ˡ�\n",
});

string long()
{
        return query("long")+
                "\nplay������\n"+
                "stop��ֹͣ\n"+
                "list���б�\n";
}

void init()
{
        add_action("do_play", "play");
        add_action("do_halt", "stop");
        add_action("do_list", "list");
}

int do_halt()
{
        object me=this_player();

        if (find_call_out("play_stage") < 0) 
                return notify_fail("�㲢û��������ѽ��\n");

        me->delete_temp("playing");
        message_vision(HIM"\n$N���ִ��һ��ʹ��ı��飬���εؿ�����������ͣ����������\n"NOR, me);
        remove_call_out("play_stage");
        return 1;
}

int do_play(string arg)
{
        object me=this_player();
        object ob=this_object();
        mapping song;
        string *context,*color;

        if (!arg) return notify_fail("��Ҫ����ʲô��\n");

        if (!mapp(song=MUSIC_D->query_song(arg)))
                return notify_fail("��Ҫ���ݵ�������������������û�С�\n");

        if (me->query_temp("playing"))
                return notify_fail("�㲻����������"+me->query_temp("playing")+"��\n");

        if (me->is_busy())
                return notify_fail("����æ���أ��Ȼ���ٱ��ݰɡ�\n");

        else {
                message_vision(HIM+start_msg[random(sizeof(start_msg))]+NOR,me,ob);
                message_vision(HIG"Ȼ��$N��������"+song["author"]+"�ġ�"+song["name"]+"������\n\n"NOR,me);

                context=explode(song["song"],"\n");
                color=song["color"];

                message_vision(color[random(sizeof(color))]+"\t   ��"+song["name"]+"������"+song["author"]+"\n\n"+NOR,me);
                call_out("play_stage",1,me,0,context,color);
                me->set_temp("playing",song["author"]+"�ġ�"+song["name"]+"��");
                me->start_busy(1);
                return 1;
        }
}

void play_stage(object me,int i,string *context,string *color)
{
        if (i<sizeof(context)) {
                message_vision(color[random(sizeof(color))]+"\t"+context[i]+"\n"+NOR,me);
                call_out("play_stage",1,me,i+1,context,color);
                me->start_busy(1);
                return;
        }
        else {
                message_vision(HIG"\n$N������������"+me->query_temp("playing")+"��\n"NOR,me);
                message_vision(HIM+end_msg[random(sizeof(end_msg))]+NOR,me,this_object());
                me->delete_temp("playing");
                return;
        }
}

int do_list(string arg)
{
        object me=this_player();
        mapping songs;
        string msg,*song;
        int i;

        if (me->is_busy())
                return notify_fail("����æ���أ��Ȼ���ٲ��İɡ�\n");

        else {
                songs=MUSIC_D->query_songs();
                song=keys(songs);
                song=sort_array(song,1);

                msg="������������������������������������������������������������\n";
                msg+=HBBLU+HIW+"\t\t     ��"MUD_NAME"��������Ŀ��                   \n"NOR;
                msg+="������������������������������������������������������������\n";

                for (i=0;i<sizeof(songs);i++) {
                        msg+=sprintf(WHT"     %-20s"NOR":%-20s\n",song[i],
                                songs[song[i]]["author"]+"��"+songs[song[i]]["name"]+"��");
                }
                msg+="������������������������������������������������������������\n";
                msg+=sprintf(HBRED HIW"%59s \n"NOR,"Ŀǰ���� "+(i+1)+" �������ɹ����ࡣ");
                msg+="������������������������������������������������������������";
                me->start_more(msg);
                return 1;
        }
}
