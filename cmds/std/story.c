// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 

inherit F_SAVE;

int main(object me, string arg)
{
   object document, content, cont_num;
   int i, j, option, month, number, year, nummonth, argn;
   string dirname="/data/doc/", deloption, srcstr, dststr, file;
   string *mon= ({"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"});

   if (! arg) {
     dirname=dirname+ctime(time())[20..23] + "/";
     option=1;
     }
   else argn=sscanf(arg, "%d %d %d %s", month, number, year, deloption);

   if ( argn >3)
     if (deloption=="-delete")
        {
        if ( (string)SECURITY_D->get_status(this_player(1)) != "(admin)"
         && (string)SECURITY_D->get_status(this_player(1)) !="(arch)" )
          return notify_fail("�㲻��ɾ���ĵ���\n");
        else argn=3;
        }
     else 
        return notify_fail("ָ���ʽ��story [<month> [<number>]] [<year>]\n");
   
   if (argn==3) { 
     option=3;
     dirname=dirname+sprintf("%d",year)+"/";
     }
   if (argn==2) 
     if (number <1996) {
        dirname=dirname+ctime(time())[20..23] + "/";
        option=3;
        }
     else {
                   dirname=dirname+sprintf("%d",number)+"/";
                   option=2;
                    }
   if (argn==1)
     if (month<1996) {
        dirname=dirname+ctime(time())[20..23] + "/";
        option=2;
        }
     else {
        dirname=dirname+sprintf("%d",month)+"/";
        option=1;
        }

   seteuid(getuid());
   cont_num=new("/obj/not.c");
   cont_num->set("file_name", dirname+"month.number");
   cont_num->restore();
   if (!objectp(cont_num) )
     return notify_fail("�ĵ���ȡʧ�ܣ�\n"); 

   if (option==1) {
     file="";
     for (i=1;i<=12;i++) 
     if (cont_num->query(mon[i-1])) {
        file+=chinese_number(i)+"�£��ܹ�"
+chinese_number(cont_num->query(mon[i-1]))
+"ƪ�ĵ���\n--------------------------------------------------------------------------------\n";
        content=new("/obj/not.c");
        content->set("file_name", dirname+"content."+mon[i-1]);
        content->restore();
        if ( !objectp(content) )
          return notify_fail("�ĵ���ȡʧ�ܣ�\n");
        file+=content->query("msg")+"\n";
        }
     me->start_more(file);
     return 1;
     }

   if (month<=0 || month >=13) return notify_fail("Ҫ�����ĵ������ڣ�\n"); 
   nummonth=cont_num->query(mon[month-1]);

   if( option==2 ) {
     if (!nummonth) return notify_fail("�������ĵ���\n");
     content=new("/obj/not.c");
     content->set("file_name", dirname+"content."+mon[month-1]);
     content->restore();
     if ( !objectp(content) )
        return notify_fail("�ĵ���ȡʧ�ܣ�\n");
     write("�ܹ�"+chinese_number(nummonth)+"ƪ�ĵ���\n--------------------------------------------------------------------------------\n");
     me->start_more(content->query("msg"));
     return 1;
     }

   if (!nummonth || nummonth < number)
     return notify_fail("Ҫ�����ĵ������ڣ�\n"); 
   document=new("/obj/not.c");
   document->set("file_name", dirname+ sprintf("%s/doc%d.%d",mon[month-1],month,number) );
   document->restore();
   if ( !objectp(document) )
     return notify_fail("�ĵ���ȡʧ�ܣ�");

   if (deloption=="-delete") {
     cont_num->set(mon[month-1], nummonth-1);
     cont_num->save();
     content=new("/obj/not.c");
     content->set("file_name", dirname+"content."+mon[month-1]);
     content->restore();
     if ( !objectp(content) )
        return notify_fail("�ĵ���ȡʧ�ܣ�\n");
     dststr=""; srcstr=content->query("msg");
     for (i=1;i<=nummonth;i++) {
        sscanf(srcstr, "[%d]%s\n%s", j, file, srcstr);
        if (i >number) file=sprintf("[%3d]", i-1)+file+"\n";
        else file=sprintf("[%3d]", i)+file+"\n";
        if (i!=number) dststr+=file; 
        }
     content->set("msg", dststr);
     content->save();
     if (nummonth==number) 
        rm(dirname+sprintf("%s/doc%d.%d.o",mon[month-1],month,number));
     else
     for (i=number+1;i<=nummonth;i++) {
        document=new("/obj/not.c");
        document->set("file_name", dirname+sprintf("%s/doc%d.%d",mon[month-1],month,i));
        document->restore();
        srcstr=document->query("msg");
        sscanf(srcstr, "[%d]%s\n%s", j, file, srcstr);
        dststr=sprintf("[%3d]", i-1)+file+"\n"+srcstr;
        document->set("file_name", dirname+sprintf("%s/doc%d.%d",mon[month-1],month,i-1));  
        document->set("msg", dststr);
        document->save();
        }
     write("�ĵ�ɾ���ɹ���\n");
     return 1;
     }
   me->start_more(document->query("msg"));
   return 1;
}

int help (object me)
{
        write(@HELP
ָ���ʽ��story <month> [<number> [<year>]]

���ָ�����������Ķ�������ĵ��������г����ܶ�ȡ���ĵ�Ŀ¼��


Example: �Ķ�ĳ���Ŀ¼��
story
story 1997

Example: �Ķ�ĳ�µ�Ŀ¼��
story 5
story 5 1997

Example: �Ķ�ĳƪ�ĵ���
story 5 1
story 5 1 1997
 
HELP
);
        return 1;
}

