// edit.c Yuj@SJ 20000212
#include <ansi.h>

int edit(function callback)
{
    write("�����뿪�� "HIY"."NOR" ȡ�������� "HIY"q\n"NOR);
    write(repeat_string("��", 39) + "\n1: ");
    input_to("input_line", "", callback, 1);
    return 1;
}

void input_line(string line, string text, function callback, int ln)
{
    if( line=="." )
    {
        if (this_object()->query_temp("big5"))
            text = CONVERT_D->b5_gb(text);
        (*callback)(text);
        return;
    }
    if( line=="q" ) {
        write("����ȡ����\n");
        return;
    }
    if (strlen(line) > 100) write(HIY + "�뽫ÿ�����ֿ����� 100 ��Ӣ�Ļ� 50 ���������ڡ�\n" NOR);
    else {
        text += line + "\n";
        ln++;
    }
    if (strlen(text) > 15000 || ln > 150)
    {
        write(HIY + "�Ѿ�д�˺ܳ��ˣ�ϵͳ�Զ���ֹ��δд�����������д��\n" NOR);
        if (this_object()->query_temp("big5")) text = CONVERT_D->b5_gb(text+"(δ�����)......\n");
        (*callback)(text);
        return;
    }
    if (strlen(text) > 10000 || ln > 100) write(HIY + "�볤����˵����������д��\n" NOR);
    write(CSI"5D" + ln + ": ");
    input_to((: input_line :), text, callback, ln);
}
