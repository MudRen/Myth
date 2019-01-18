//Cracked by Roath

#define DIR "/data/comment/"
#include <ansi.h>
inherit ROOM;

int in_chinese(string);
mapping get_info(string);

string* get_info_string(string); 
void create() {
  
  set("short","������");
  set("long",@LONG

һ�䲻��ķ��䣬���õõ������£����ܵ��ļ�����
�����˸�ʽ�����ľ��ڡ�����������Բ鿴(consult)
���˶����������������ۣ�Ҳ����д��(comment)
���ĳ�˵Ŀ�����

LONG);
  set("exits",([
       "out":"/d/wiz/comment",
     ]));

  set("no_fight", 1);
  set("no_magic", 1);

  setup();
}

void init() {
  add_action("do_consult","consult");
  add_action("do_comment","comment");
  add_action("do_clear","clear");

}

int do_consult(string arg) {
   string str,name,nick,title,desc;
   string* comments;
   object ob;

   if (!arg) return notify_fail("��ʽ��consult <id>\n");
   if( file_size(DATA_DIR + "login/" + arg[0..0] + "/" + arg + __SAVE_EXTENSION__)<0 )
                return notify_fail("û����λ��ҡ�\n");
  
   seteuid(arg);
   ob = new(USER_OB);
   ob->set("id", arg);
   if (ob->restore()) {
     name=ob->query("name");
     if (!title=ob->query("title")) title="��";
     if (!nick=ob->query("nickname")) nick="��";
     if (!desc=ob->query("long")) desc="��";
   }
   destruct (ob);
       
   write("�ɣģ� "+arg+"\n");
   write("������ "+name+"\n");
   write("ͷ�Σ� "+title+"\n");
   write("�ºţ� "+nick+"\n");
   write("������ \n"+desc+"\n");
   write("������\n\n");
  
   if (file_size(DIR+arg)<0) {
       write("��\n\n");
       return 1;
   }
   
   comments=get_info_string(DIR+arg);
   set("comments",comments);
   for (int i=0;i<sizeof(comments)-2;i++)
      write(comments[i]);
   return 1;
}

int do_comment(string arg) {
  string str,name,comment,option;
  mapping comments;
  object me=this_player();
  string fail_msg="��ʽ��comment <id> <comment> <-s>(optional)\n"+
         "��ע��ϵͳ������ʾ������֣�������-sǩ����Ĵ�����\n"+
         "      comment������ʹ�ÿո����\n"+
         "      ��һ���빫�ţ���ţ�β��ء����±�ǰǧ�����أ�\n"+
         "      ���б��󣬿���clearɾ����\n"+
         "      ����������ˡ���뵵��\n";
  if (!arg) return notify_fail(fail_msg);
  if (sscanf(arg,"%s %s %s",name,comment,option)!=3 ) 
    if (sscanf(arg,"%s %s",name,comment)!=2) 
       return notify_fail(fail_msg);
  if (option && option!="-s")
    return notify_fail(fail_msg);
  if (!in_chinese(comment))
    return notify_fail("�����塣������������������д�����\n");
  if (option=="-s") 
    comment=me->query("name")+"("+me->query("id")+")��"+comment;
  if( file_size(DATA_DIR + "login/" + name[0..0] + "/" + name + __SAVE_EXTENSION__)<0 )
                return notify_fail("û����λ��ҡ�\n");

  if (!comments=get_info(DIR+name)) comments=allocate_mapping(10);
  if (comments[me->query("id")]) 
    return notify_fail("���Ѿ����������ˡ�\n");

  if (sizeof(comment)>90) return notify_fail("д�ü�̶�ҪЩ��\n");

  message_vision("$N��һ˼�����˱���ɣ���"+name+"�ĵ�����д��һ�����\n",me);
  comments[me->query("id")]=comment+"\n";
  log_file("star_comment",sprintf("On %s,%s(%s)��Ϊ%s��%s\n",
     ctime(time()),me->query("name"),geteuid(me),name,comment));
  write_file(DIR+name,me->query("id")+" "+comment+"\n",0);
  return 1;
}

mapping get_info(string file) {
  mapping comments=([]);
  string str,name,comment;
  int line=1;
  while(str=read_file(file,line,1)) {
    sscanf(str,"%s %s",name,comment);
    comments=comments+([name:comment]);
    line++;
  }
  return comments;
}

string* get_info_string(string file) {
  string *comments=({});
  string str,name,comment;
  int line=1;
  while(str=read_file(file,line,1)) {
    sscanf(str,"%s %s",name,comment);
    comments=comments+({comment});
    line++;
  }
  return comments;
}

int do_clear(string arg) {
  object me=this_player();
  mapping comments;
  int line=1;
  string str,name,comment;

   if (!arg) return notify_fail("��ʽ��clear <id>\n");
   if (file_size(DIR+arg)<0)
      return notify_fail("û�����������\n");

   comments=get_info(DIR+arg);      
   if (!comments[me->query("id")]) 
      return notify_fail("û�з������ī����\n");
   message_vision("$N���˲�ע�⣬�ӵ�����˺��һҳ�����ڻ��\n",me);

   while(str=read_file(DIR+arg,line,1)) {
     sscanf(str,"%s %s",name,comment);
     if (name!=me->query("id"))
       write_file(DIR+arg+".bak",str,0);
     line++;
  }
  rm(DIR+arg);
  if (file_size(DIR+arg+".bak")>=0)
      rename(DIR+arg+".bak",DIR+arg);

  return 1;
}
  

int in_chinese(string str) {
  int len=strlen(str);

  if (len<2) return 0;
  for (int i=0;i<len;i=i+2)
  if (!is_chinese(str[i..i+1])) return 0;

  return 1;
}
