//***************************************
//MUDLIB：Biographies         〓悟空传〓   
//VERSION：Test 1.6.28   
//ENCODING：GB  
//Created Admin：By Waiwai           
//Admin Email：wkzstory@21cn.com         
//***************************************
//Created by waiwai@2000/12/22
//Last modified by waiwai@2001/06/28
#include <ansi.h>
#include <mudlib.h>
#include <command.h>

#define BOARD_CAPACITY query("capacity")
#define MAILBOX "/obj/mailbox"

inherit ITEM;
inherit F_SAVE;
string query_master();

void setup()
{
       string loc;

       if( stringp(loc = query("location")) ) move(loc);
       set("no_get", 1);

       restore();
}

void init()
{
       add_action("do_post", "post");
       add_action("do_read", "read");
       add_action("do_discard", "discard");
       add_action("do_appoint","banzhu");
       add_action("do_demit","bamian");
       add_action("do_lock", "lockb");
       add_action("do_unlock", "unlockb");
       add_action("do_forward", "zhuanxin");
       add_action("do_document", "document");
}

string query_save_file()
{
       string id;

       if( !stringp(id = query("board_id")) ) return 0;
       return DATA_DIR + "board/" + id;
}

string query_master()
{
       if( query("master") )
               return query("master");
       else
               return "尚未任命";
}

string short()
{
       mapping *notes;
       int i, unread, last_read_time;

       notes = query("notes");
       if( !pointerp(notes) || !sizeof(notes) )
               return ::short() + " ["HIC" 没有任何留言   "HIG"本板版主："HIY+query_master()+NOR" ]";

       if( this_player() ) {
               last_read_time = (int)this_player()->query("board_last_read/" + (string)query("board_id"));
               for(unread = 0, i=sizeof(notes)-1; i>=0; i--, unread ++)
                       if( notes[i]["time"] <= last_read_time ) break;
       }
       if( unread )
return sprintf(HIC"%s"NOR" ["HIC" %d"HIM" 张留言，"HIY"%d"HIR" 张未读   "HIG
"本板版主："HIY+query_master()+NOR" ]", ::short(), sizeof(notes), unread);
       else
    return sprintf(HIC"%s"NOR" [ "HIC"%d"HIM" 张留言   "HIG"本板版主："HIY+query_master()+NOR
" ]", ::short(), sizeof(notes));
}

string long()
{
  mapping *notes;
  int i, last_time_read;
  string msg, myid;

  notes = query("notes");
  msg=sprintf(HBBLU HIY" 本版版主：%-10s                                        %-20s \n"NOR,
               query_master(),query("name"));
    msg +=HBBLU HIY" 序号   读取      留 言 时 间       留言人                    留  言  主  题        \n"NOR;

  if( !pointerp(notes) || !sizeof(notes) ) return query("long");

  last_time_read = this_player()->query("board_last_read/" + (string)query("board_id"));

  for(i=sizeof(notes)-1; i>=0; i--)
    msg += sprintf("[%3d] %4s  [%s] %-20s 主题→ %s\n",
      i+1, ( notes[i]["time"] > last_time_read ? HIR"(未读)"NOR: WHT"(已读)"NOR),
BJTIME_CMD->chinese_time(7, ctime(notes[i]["time"])),
notes[i]["author"], notes[i]["title"]);
    msg+=HBBLU HIY" 序号   读取      留 言 时 间       留言人                    留  言  主  题        \n"NOR;
msg+=HBBLU HIY" 欢迎光临"+INTERMUD_NAME+"                        本站地址："+MUD_IP+"  \n"NOR;

  return msg;
}

//By waiwai@2001/03/05 changed.
int do_appoint(string arg)
{
       object me = this_player();

  if( (string)SECURITY_D->get_status(this_player(1)) != "(admin)"
   && (string)SECURITY_D->get_status(this_player(1)) !="(arch)"
&& query("master")!=this_player(1)->query("id"))
   return notify_fail("你没有委任版主的权利!\n");
   
   if( wizardp(me) ) {
   if( !arg)
       return notify_fail("你要委任谁为本版版主？\n");
} else {
   if( !arg)
       return notify_fail("你要将本版版主职位转任给谁？\n");
}
   if( !present(arg,environment(me) ) )
       return notify_fail("你要任命的玩家不在这个地方！\n");

//    if(this_object()->query("master") )
//                return notify_fail("这个版已经有版主了！\n");

   if( ! wizardp(me) && userp(me) ) {

}
   this_object()->set("master",arg);

   if( wizardp(me) ) 
   message("system",HIR"【版主公告】"+me->name(1)+"任命 "HIG+arg+HIR" 为 "HIW+
this_object()->name()+HIR" 版主！\n"NOR,users());
else
   message("system",HIR"【版主公告】现任"+this_object()->name()+HIR"版主"+me->name(1)+"将版主职位转任给"+arg+"！\n"NOR,users());

    log_file("static/zhuanren",sprintf("%s(%s)将%s版主职位转任给%s 时间在: (%s) \n",
me->name(1),geteuid(me),this_object()->name(),arg,
COLOR_D->clean_color(BJTIME_CMD->chinese_time(7, ctime(time()) )  ))); 

   save();      
 return 1;
}

//By waiwai@2001/03/05 changed.
int do_demit()
{
       object me = this_player();

  if( (string)SECURITY_D->get_status(this_player(1)) != "(admin)"
   && (string)SECURITY_D->get_status(this_player(1)) !="(arch)"
&& query("master")!=this_player(1)->query("id"))

   return notify_fail("你没有罢免版主的权利!\n");

   if(!this_object()->query("master") )
               return notify_fail("这个版本来就没有版主！\n"); 

   if( wizardp(me) ) 
   message("system",HIR"【版主公告】"+me->name(1)+"罢免了 "HIW+this_object()->name()+HIR" 版主 "+
                   this_object()->query("master") +" ！\n"NOR,users());
else
   message("system",HIR"【版主公告】"+me->name(1)+"放弃了 "HIW+this_object()->name()+HIR" 版主的职位 ！\n"NOR,users());

   this_object()->delete("master");
   save();
 return 1;
}

void done_post(object me, mapping note, string text)
{
       mapping *notes;
       int i;
       string msg="";

       note["time"] = time();

      if (me->query("signature")) {
               note["msg"]=COLOR_D->replace_color(text+HIB"\n
──── 个 ── 性 ── 签 ── 名 ────\n\n"NOR+me->query("signature"),1);
       }
       else note["msg"]=COLOR_D->replace_color(text,1);  

       notes = query("notes");
       if( !pointerp(notes) || !sizeof(notes) )
               notes = ({ note });
       else
               notes += ({ note });

       if( sizeof(notes) > BOARD_CAPACITY )
               notes = notes[BOARD_CAPACITY / 4 .. BOARD_CAPACITY];//自动删除数目为1/4.

       set("notes", notes);
       save();
  for(i=sizeof(notes)-1; i>=0; i--)

       note["msg"] = HIG"来自 "HIR + ::short() + HIY"  内容如下:\n\n" NOR+ text;
       "/obj/board/post_b"->done_post(me, note);
       restore();
       tell_object(me, HIC"留言完毕。\n"NOR);
// message("channel:rumor", HIW"【天神之眼】"+me->name(1)+"("+me->query("id")+")刚刚在"HIG+::short()+HIW
// "发表了一个帖子。\n\n"NOR, users());

       return;
}

int do_post(string arg)
{
       mapping note;
       object me;
       me = this_player();

  //By waiwai@2001/02/26 设置禁止(post_limit参数以后将逐渐替换为wiz_board)
  if(!wizardp(me) && environment(me)->query("post_limit"))
     return notify_fail(HIC"只有巫师才可以在这里留言。\n"NOR);

  if(!wizardp(me) && environment(me)->query("wiz_board"))
     return notify_fail(HIC"只有巫师才可以在这里留言。\n"NOR);

  if(!arg) return notify_fail(HIC"留言请指定一个标题。\n"NOR);
  if(strlen(arg) > 20 ) return notify_fail(HIR"标题过长！\n"NOR);

  if( me->query("no_board") && !wizardp(me)) //By waiwai@2001/06/28
        return notify_fail(HIC"你已经被剥夺了在任何留言板留言的资格。\n"NOR);

   //By waiwai@2001/03/06 设置禁止
   if((int)me->query_skill("literate",1) < 30 && !wizardp(me))
 return notify_fail(WHT"你的读书识字小于30,没有在这个版留言的权利。\n"NOR);

   if ( time() - me->query_temp("last_time/post") < 600 && !wizardp(me))
 return notify_fail(WHT"你只能在上次留言10分钟以后才可以再留言。\n"NOR);

      me->set_temp("last_time/post",time());

      note = allocate_mapping(4);
      note["title"] = arg;
note["author"] = this_player()->name(1)+
"("+capitalize(this_player()->query("id"))+")";//By waiwai@2001/03/05 changed.
       this_player()->edit( (: done_post, this_player(), note :) );
       return 1;
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
               return notify_fail(HIC"留言板上目前没有任何留言。\n"NOR);

       if( !arg ) return notify_fail(HIC"指令格式：read <留言编号|new|next>\n"NOR);
       if( arg=="new" || arg=="next" ) {
               if( !mapp(last_read_time) || undefinedp(last_read_time[myid]) )
                       num = 1;
               else
                       for(num = 1; num<=sizeof(notes); num++)
                               if( notes[num-1]["time"] > last_read_time[myid] ) break;

       } else if( !sscanf(arg, "%d", num) )
               return notify_fail(HIC"你要读第几张留言？\n"NOR);

       if( num < 1 || num > sizeof(notes) )
               return notify_fail(HIC"已经没有未读的更新留言。\n"NOR);
       num--;
       this_player()->start_more( sprintf("\n\n%s\n"HIM"留言主题： %s\n"HIY"留 言 人： %s\n"
HIW"留言时间： %s\n"NOR WHT
       "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n"NOR,
               BBLU HIG+query("name")+NOR HIG" 第 "HIR+chinese_number(num + 1)+HIG" 号留言"NOR, 
               COLOR_D->replace_color(notes[num]["title"],1), notes[num]["author"],
BJTIME_CMD->chinese_time(1, ctime(notes[num]["time"])))
               + COLOR_D->replace_color(notes[num]["msg"],1)+NOR
       WHT"━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n"NOR,);

       if( !mapp(last_read_time) )
               this_player()->set("board_last_read", ([ myid: notes[num]["time"] ]) );
       else 
               if( undefinedp(last_read_time[myid]) || notes[num]["time"] > last_read_time[myid] )
                       last_read_time[myid] = notes[num]["time"];

       return 1;
}

//By waiwai@2001/03/05 changed.
int do_discard(string arg)
{
mapping *notes;
int num;
object me = this_player();
int n_start,n_end=0;
if( !arg || (sscanf(arg, "%d to %d", n_start,n_end)!=2 
  && sscanf(arg,"%d",n_start)!=1))
return notify_fail(HIC"指令格式：discard <留言编号>\n"NOR);
notes = query("notes");
if (n_end==0) n_end=n_start;
if( !arrayp(notes) || n_start < 1 || n_end > sizeof(notes) )
return notify_fail(HIC"没有这张留言。\n"NOR);
num=n_end;
while(num>=n_start) {
num--;
if( notes[num]["author"] != 
 (string) this_player(1)->query("name")+
 "("+capitalize(this_player(1)->query("id"))+")"
&& query("master")!=this_player(1)->query("id")
&& (string)SECURITY_D->get_status(this_player(1)) != "(admin)" ) {
      write(sprintf(HIC"第"HIR"%d"HIC"号留言不是你写的,你又不是版主。\n"NOR,num));
return 1;
}
}

       if(notes[num]["lock"]){
               return notify_fail(HIW"这张留言被加锁了,请先解锁 "HIR"(unlockb) \n"NOR);
       }

if (n_start >1)
            notes = notes[0..num-1] + notes[n_end..sizeof(notes)-1];
       else
         notes =notes[n_end..sizeof(notes)-1];
set("notes", notes);
save();
write(HIC"删除第 " HIR+ (n_start) +HIC " 号到第 "HIR+(n_end)+HIC" 号留言....Ok。\n"NOR);
log_file("static/POSTING", COLOR_D->clean_color(BJTIME_CMD->chinese_time(7,ctime( time()) ))+": "
               +me->name(1)+"("+me->query("id")+")"
+" 删除了"+::short()+"的第"+(n_start)+"到"+(n_end)+"号留言。\n");

return 1;
}

//By waiwai@2001/04/25 added.
int do_lock(string arg)
{
       mapping *notes;
       int num;
       
       if( !arg || sscanf(arg, "%d", num)!=1 )
               return notify_fail(HIC"指令格式：lockb <留言编号>\n"NOR);
       notes = query("notes");
       if( !arrayp(notes) || num < 1 || num > sizeof(notes) )
               return notify_fail(HIC"没有这张留言。\n"NOR);
       num--;
       if(notes[num]["lock"]){
               return notify_fail(HIW"这张留言已经加锁了。\n"NOR);
       }
       if( !wizardp( this_player(1)) ) return notify_fail(HIC"你没权加锁。\n"NOR);
       notes[num]["lock"]=1;
       set("notes", notes);
       save();
       write(HIY"加锁...第 " HIR+ (num+1) +HIY " 号留言....成功。\n"NOR);
       return 1;

}

//By waiwai@2001/04/25 added.
int do_unlock(string arg)
{
       mapping *notes;
       int num;
       
       if( !arg || sscanf(arg, "%d", num)!=1 )
               return notify_fail(HIC"指令格式：unlockb <留言编号>\n"NOR);
       notes = query("notes");
       if( !arrayp(notes) || num < 1 || num > sizeof(notes) )
               return notify_fail(HIC"没有这张留言。\n"NOR);
       num--;
       if(!notes[num]["lock"]){
               return notify_fail(HIW"这张留言没有加锁。\n"NOR);
       }
       if( !wizardp( this_player(1)) ) return notify_fail(HIR"你没权解锁。\n"NOR);
       notes[num]["lock"]=0;
       set("notes", notes);
       save();
       write(HIY"解锁...第 " HIR+ (num+1) +HIY " 号留言....Ok。\n"NOR);
       return 1;
}

//By waiwai@2001/05/01 added.
int do_forward(string arg)
{
       mapping *notes;
       mapping m;
       int num;
       string dest;
       object me;
       me = this_player();
       
if((int)me->query_skill("literate",1) < 30 && !wizardp(me))
 return notify_fail(WHT"你的读书识字小于30,还没有转信的权利。\n"NOR);

        if ( time() - me->query_temp("last_time/zhuanxin") < 1800 && !wizardp(me))
 return notify_fail(WHT"你只能在上次转信30分钟以后才可以再次转信。\n"NOR);

       me->set_temp("last_time/zhuanxin",time());

       if( !arg || sscanf(arg, "%d %s", num, dest)!=2 )
            return notify_fail(HIY"你要将哪一张留言转寄给别人？"HIR"( 格式：zhuanxin 留言编号 对方id )\n"NOR);

       notes = query("notes");
       if( !arrayp(notes) || num < 1 || num > sizeof(notes) )
               return notify_fail(HIC"没有这张留言。\n"NOR);
       num--;

       m = ([]);
       m["title"] = notes[num]["title"];
       m["text"] = notes[num]["msg"];
       m["time"] = notes[num]["time"];
       m["from"] = "/信息来源："+::short()+",转寄自" + this_player()->query("name")+"("+this_player()->query("id")+")";
       m["to"] = dest;
       MAILBOX->send_mail( dest, m );
       write("OK!\n");
   //By waiwai@2001/06/05 增加监控以及log.
    log_file("static/zhuanxin",sprintf("%s(%s)用转发信件功能转发"+::short()+"
主题为"+m["title"]+"的留言给"+m["to"]+"  时间在: (%s) \n",
me->name(1),geteuid(me),COLOR_D->clean_color(BJTIME_CMD->chinese_time(7, ctime(time()))) ) ); 
// message("channel:rumor", HIW"【天神之眼】"+me->name(1)+"("+me->query("id")+")正在转发"HIG+::short()+HIW"主题为
// \t\t\t  "HIR+m["title"]+HIW" 的留言给"HIY+m["to"]+"\n"NOR, users());

       return 1;
}

int do_document(string arg)
{
        object document, content, cont_num;
   string mon, dirname="/data/";
   int month, num, nummonth, defmon, defyear, argn;
        mapping *notes;
   string 
*strmon=({"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct",
"Nov","Dec"});

   if( (string)SECURITY_D->get_status(this_player(1)) != "(admin)"
    && (string)SECURITY_D->get_status(this_player(1)) !="(arch)" )
     return notify_fail("你没有存档的权力！\n");

//by mon. 9/6/97
        if(environment(this_player())->query("wiz_board"))
     dirname+="wiz_doc/";
        else
     dirname+="doc/";

        if( ! arg ) return notify_fail("指令格式：document <留言编号>\n"); // Add By Mudring@sjsh

   argn=sscanf(arg, "%d %d %d", num, defmon, defyear);

        if( argn >3) // delete !arg here by mudring@sjsh
                return notify_fail("指令格式：document <留言编号>\n");

   if (argn==3) {
     dirname = dirname + sprintf("%d",defyear)+"/";
     month=defmon;
     mon="Null";
     }
   if (argn==2) {
     if (defmon>1995) {
        dirname = dirname + sprintf("%d",defmon)+"/";    
        mon=ctime(time())[4..6];
        }
     else {
        dirname = dirname + ctime(time())[20..23] + "/";
        month=defmon;
        mon="Null";
        }
     }
   if (argn==1) {
     dirname = dirname + ctime(time())[20..23] + "/";
     mon=ctime(time())[4..6];
     }
   if ( mon=="Null" ) {
     if (month>12 || month<1) return notify_fail("要存的月份不存在！\n");
     mon=strmon[month-1];
     }
   else switch (mon) {
     case "Jan": month=1; break;
                case "Feb": month=2; break;
                case "Mar": month=3; break;
                case "Apr": month=4; break;
                case "May": month=5; break;
                case "Jun": month=6; break;
                case "Jul": month=7; break;
                case "Aug": month=8; break;
                case "Sep": month=9; break;
                case "Oct": month=10; break;
                case "Nov": month=11; break;
                case "Dec": month=12; break;
     }

   if (month>12 || month<1) return notify_fail("要存的月份不存在！\n");


   notes = query("notes");
   if( !arrayp(notes) || num < 1 || num > sizeof(notes) )
     return notify_fail("没有这张留言。\n");
   num--;

   cont_num=new("/obj/not.c");
   cont_num->set("file_name", dirname+"month.number");
        cont_num->restore();

   if (!objectp(cont_num) )
                return notify_fail("文档读取失败！\n");
   nummonth=cont_num->query(mon);
   nummonth++;
   cont_num->set(mon, nummonth);
   if (!cont_num->save())
     return notify_fail("存档失败！\n");

   content=new("/obj/not.c");
   content->set("file_name", dirname+"content."+mon);
   content->restore();
   if ( !objectp(content) )
     return notify_fail("文档读取失败！\n");
   if (content->query("msg")) content->set("msg", content->query("msg")+ 
sprintf("[%3d] %-40s %12s (%s)\n",
nummonth, notes[num]["title"], notes[num]["author"], 
ctime(notes[num]["time"])[0..9])
);
   else content->set("msg", sprintf("[%3d] %-40s %12s (%s)\n",nummonth, 
notes[num]["title"], notes[num]["author"], 
ctime(notes[num]["time"])[0..9]));

   if (!content->save())
                return notify_fail("存档失败！\n");

   document=new("/obj/not.c");
   document->set("file_name", dirname+ sprintf("%s/doc%d.%d",mon,month, 
nummonth) );
   document->restore();
   if ( !objectp(document) )
     return notify_fail("文档读取失败！");
   document->set("msg",
sprintf("[%3d] %-40s %12s 
(%s)\n----------------------------------------------------------------
----------------\n", nummonth, notes[num]["title"], 
notes[num]["author"], ctime(notes[num]["time"])[0..9])
+ notes[num]["msg"]
);
   if (!document->save())
     return notify_fail("存档失败！\n");
   write("OK.\n");
   
/*
   if (num >0)
             notes = notes[0..num-1] + notes[num+1..sizeof(notes)-1];
        else
          notes =notes[num+1..sizeof(notes)-1];
        set("notes", notes);
        save();
*/
   return 1;
}   



