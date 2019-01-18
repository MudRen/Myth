//***************************************
//MUDLIB��Biographies         ����մ���   
//VERSION��Test 1.6.28   
//ENCODING��GB  
//Created Admin��By Waiwai           
//ADMINEMAIL��wkzstory@21cn.com         
//***************************************
//OBJ BOARD post_b.c
//Created by waiwai@2000/12/22
//��Ϸ���������԰��ܻ�.

#include <ansi.h>
#include <mudlib.h>
#include <command.h>

#define BOARD_CAPACITY query("capacity")
string replace_color(string msg,int flag);

inherit ITEM;
inherit F_SAVE;

void setup()
{
        string loc;

        if( stringp(loc = query("location")) )
                move(loc);
        set("no_get", 1);
        restore();
}

void init()
{
        add_action("do_post", "post");
        add_action("do_read", "read");
        add_action("do_discard", "discard");
}

string query_save_file()
{
        string id;

        if( !stringp(id = query("board_id")) ) return 0;
        return DATA_DIR + "board/" + id;
}

string short()
{
        mapping *notes;
        int i, unread, last_read_time;

        notes = query("notes");
        if( !pointerp(notes) || !sizeof(notes) )
                return ::short() + " ["HIC" Ŀǰû���κ����Ի���"NOR" ]";

        if( this_player() ) {
                last_read_time = (int)this_player()->query("board_last_read/" + (string)query("board_id"));
                for(unread = 0, i=sizeof(notes)-1; i>=0; i--, unread ++)
                        if( notes[i]["time"] <= last_read_time ) break;
        }
        if( unread )
return sprintf(HIC"%s"NOR" ["HIM" Ŀǰ������"HIY" %d"HIM" �����ԣ����� "HIR"%d"HIM" ��δ��"NOR" ]", ::short(), sizeof(notes), unread);
        else
     return sprintf(HIC"%s"NOR" [ "HIM"Ŀǰ������ "HIW"%d"HIM" ������"NOR" ]", ::short(), sizeof(notes));
}

string long()
{
   mapping *notes;
   int i, last_time_read;
   string msg, myid;

   notes = query("notes");
    msg=HBBLU HIY" ���   ��ȡ      �� �� ʱ ��       ������                    ��  ��  ��  ��        \n"NOR;

   if( !pointerp(notes) || !sizeof(notes) ) return query("long");

   last_time_read = this_player()->query("board_last_read/" + (string)query("board_id"));

   for(i=sizeof(notes)-1; i>=0; i--)
     msg += sprintf("[%3d] %4s  [%s] %-20s ����� %s\n",
       i+1, ( notes[i]["time"] > last_time_read ? HIR"(δ��)"NOR: WHT"(�Ѷ�)"NOR),
BJTIME_CMD->chinese_time(7, ctime(notes[i]["time"])),
notes[i]["author"], notes[i]["title"]);
    msg+=HBBLU HIY" ���   ��ȡ      �� �� ʱ ��       ������                    ��  ��  ��  ��        \n"NOR;
msg+= HBBLU HIY+INTERMUD_NAME+"���԰��ܻ�                         ��վ��ַ��"+MUD_IP+"\n"NOR;

   return msg;
}

int do_post()
{
   string arg;

   if(!arg) return notify_fail(HIR"���԰��ܻ��ֹ�������ԡ�\n"NOR);

    return 1;
}

void done_post(object me, mapping note)
{
        mapping *notes;

        notes = query("notes");
        if( !pointerp(notes) || !sizeof(notes) )
                notes = ({ note });
        else
                notes += ({ note });

        if( sizeof(notes) > BOARD_CAPACITY )
                notes = notes[BOARD_CAPACITY / 100 .. BOARD_CAPACITY];

        set("notes", notes);
        save();
        return;
}

int do_read(string arg)
{
        int num;
        mapping *notes, last_read_time;
        string myid;

        last_read_time = this_player()->query("board_last_read");
        myid = query("board_id");
        notes = query("notes");

        if( !pointerp(notes) || !sizeof(notes) )
                return notify_fail(HIC"Ŀǰû���κ����Ի��ܡ�\n"NOR);

        if( !arg ) return notify_fail(HIC"ָ���ʽ��read <���Ա��|new|next>\n"NOR);
        if( arg=="new" || arg=="next" ) {
                if( !mapp(last_read_time) || undefinedp(last_read_time[myid]) )
                        num = 1;
                else
                        for(num = 1; num<=sizeof(notes); num++)
                                if( notes[num-1]["time"] > last_read_time[myid] ) break;

        } else if( !sscanf(arg, "%d", num) )
                return notify_fail(HIC"��Ҫ���ڼ������ԣ�\n"NOR);

        if( num < 1 || num > sizeof(notes) )
                return notify_fail(HIC"�Ѿ�û��δ���ĸ������ԡ�\n"NOR);
        num--;
        this_player()->start_more( sprintf("\n\n%s\n"HIM"�������⣺ %s\n"HIY"�� �� �ˣ� %s\n"
HIW"����ʱ�䣺 %s\n"NOR WHT
        "������������������������������������������������������������������������������������\n"NOR,
                BBLU HIG+query("name")+NOR HIG" �� "HIR+chinese_number(num + 1)+HIG" ������"NOR, 
                replace_color(notes[num]["title"],1), notes[num]["author"],
BJTIME_CMD->chinese_time(1, ctime(notes[num]["time"])))
                + replace_color(notes[num]["msg"],1)+NOR
        WHT"\n�������������������������������������������������������������������������� "HIG"["HIR" ������"HIG" ] \n"NOR, );

        if( !mapp(last_read_time) )
                this_player()->set("board_last_read", ([ myid: notes[num]["time"] ]) );
        else 
                if( undefinedp(last_read_time[myid]) || notes[num]["time"] > last_read_time[myid] )
                        last_read_time[myid] = notes[num]["time"];

        return 1;
}

int do_discard(string arg)
{
        mapping *notes;
        int num;
        object me = this_player();
        int n_start,n_end=0;
        if( !arg || (sscanf(arg, "%d to %d", n_start,n_end)!=2 
           && sscanf(arg,"%d",n_start)!=1))
                return notify_fail(HIC"ָ���ʽ��discard <���Ա��>\n"NOR);
        notes = query("notes");
        if (n_end==0) n_end=n_start;
        if( !arrayp(notes) || n_start < 1 || n_end > sizeof(notes) )
                return notify_fail(HIC"û���������ԡ�\n"NOR);
        num=n_end;
        while(num>=n_start) {
        num--;
        if( notes[num]["author"] != 
          (string) this_player(1)->query("name")+
          "("+capitalize(this_player(1)->query("id"))+")"
        && (string)SECURITY_D->get_status(this_player(1)) != "(admin)" ) {
       write(sprintf(HIW"��"HIR"%d"HIW"����������Ȩɾ����\n"NOR,num));
                return 1;       
        }
        }

        if (n_start >1)
             notes = notes[0..num-1] + notes[n_end..sizeof(notes)-1];
        else
          notes =notes[n_end..sizeof(notes)-1];
        set("notes", notes);
        save();
        write(HIC"ɾ���� " HIR+ (n_start) +HIC " �ŵ��� "HIR+(n_end)+HIC" �Ż�������....Ok��\n"NOR);
        log_file("static/POSTING", ctime( time() )+": "
                +me->query("name")+"("+me->query("id")+")"
                +" ɾ����"+::short()+"�ĵ�"+(n_start)+"��"+(n_end)+"�Ż������ԡ�\n");
        
        return 1;
}

void create()
{
        set_name(HIG"���԰��ܻ�"NOR, ({ "board" }) );
        set("location", "/d/wiz/wizroom1");
        set("board_id", "post_b");
        set("long", "���ǻ㼯��������������Ե����԰塣\n" );
        setup();
        set("capacity", 999);
}

string replace_color(string msg,int flag)
{
        msg = replace_string(msg, "$BLK$", flag?BLK:"");
        msg = replace_string(msg, "$RED$", flag?RED:"");
        msg = replace_string(msg, "$GRN$", flag?GRN:"");
        msg = replace_string(msg, "$YEL$", flag?YEL:"");
        msg = replace_string(msg, "$BLU$", flag?BLU:"");
        msg = replace_string(msg, "$MAG$", flag?MAG:"");
        msg = replace_string(msg, "$CYN$", flag?CYN:"");
        msg = replace_string(msg, "$WHT$", flag?WHT:"");
        msg = replace_string(msg, "$HIR$", flag?HIR:"");
        msg = replace_string(msg, "$HIG$", flag?HIG:"");
        msg = replace_string(msg, "$HIY$", flag?HIY:"");
        msg = replace_string(msg, "$HIB$", flag?HIB:"");
        msg = replace_string(msg, "$HIM$", flag?HIM:"");
        msg = replace_string(msg, "$HIC$", flag?HIC:"");
        msg = replace_string(msg, "$HIW$", flag?HIW:"");
        msg = replace_string(msg, "$NOR$", flag?NOR:"");
        msg = replace_string(msg, "$BLINK$", flag?BLINK:"");
        if(flag) msg+=NOR;
        return msg;
}

